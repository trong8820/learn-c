# learn-c

Reference  
1. https://www.geeksforgeeks.org/c-programming-language/
2. C in a Nutshell
3. C Primer Plus
4. C Programming Cookbook
5. Century C
6. Data Structures Using C
7. Exterme C
8. Modern C (Next)
9. Modern C for Absolute Beginners

## Comment
```c
#if 0
	...
#endif
```

## Wide characters
```c
#include <stddef.h>

wchar_t wc = '\x3b1';
```
Not all compilers support universal character names

## Digraphs and Trigraphs
```c
int arr<::>=<%10,20,30%>;
printf("The second array element is <%d>.\n", arr<:1:>);

int arr[]={10,20,30};
printf("The second array element is <%d>.\n", arr[1]);
```
| Digraph | Equivalent |
| - | - |
|<:|[|
|:>|]|
|<%|{|
|%>|}|
|%:|#|
|%:%:|##|
or trigraphs Ex: ```??(``` -> ```[```
```c
printf("Cancel???(y/n) ");

printf("Cancel?[y/n) ");

printf("Cancel\?\?\?(y/n) "); // Cancel???(y/n) 
```
## Enum
```c
enum {OFF, ON, STOP=0, GO=1, CLOSED=0, OPEN=1};

// Auto size
typedef enum A { OFF, ON }; // sizeof A; 4
typedef enum B { OFF, ON = 0xFFFFFFFFFFFFFFFF }; // sizeof B; 8
```
## The Alignment of Objects
```c
// C11
_Alignas(4) short a; // sizeof a; 2 and _Alignof(a); 4
// #include <stdalign.h> _Alignas -> alignas and _Alignof alignof
```
## Literals
| Suffix | Type |
| - | - |
| 0 | int |
| 0U | unsigned int |
| 0L | long |
| 0UL | unsigned long |
| 0LL | long long |
| 0llu | unsigned long long |
| 0.0 | double |
| 0.0f | float |
| 0.0L | long double |

| Literals | Type |
| - | - |
| 85 | decimal |
| 0213 | octal |
| 0x4b | hexadecimal |

```c
// Float [+/-] <Mantissa> <e/E> [+/-] <Exponent>
double a = 67e-12; // 64.0*10^-12
```
| Prefix | Examples | Type |
| - | - | - |
| none | 'a', '\t' | int |
| L | L'a', L'\u0100' | wchar_t (stddef.h) |
| u | u'a', u'x3b3' | char16_t (uchar.h) |
| U | U'a', U'\u24FA'| char32_t (uchar.h) |

Escape sequences: \o[oct], \x[hex], \u or \U universal character
Wide-string literal is defined using the prefix L: ```L"Hello"```

```c
// Multiple line
char* str1 = "xin \
chao";

char* str2 = 
"string1\n"
"string2";

char* str3 = R"(
	string1
	string2
)";
```
## Generic Selections C11
```c
// _Generic (expression, generic association 1 [, generic association 2, ...])
#define get_type(expr)    \
	_Generic((expr),      \
	       int : "int",   \
	      char : "char",  \
	    double : "double" \
	)

#define cbrt(X)              \
	_Generic((X),            \
	    long double : cbrtl, \
	        default : cbrt,  \
	          float : cbrtf  \
	)(X)
```
## Pointer arithmetic
```c
doubled dArr[5]={0.0,1.1,2.2,3.3,4.4}, *dPtr = dArr;
dPtr = dPtr + 2;
int i = dPtr - dArr; // 2, the index of the array element that dPtr pointer to.
// The type of i: ptrdiff_t (stddef.h)
```

## Array
```c
int a[] = { [1000] = -1 }; // Create an array of 1001 elements
```

## Flexible Structure
```c
typedef struct { int len; float array[]; } DynArray_t;
// sizeof DynArray_t = 4
DynArray_t * daPtr = malloc(sizeof(DynArray_t) + 10*sizeof(float));
// This initialization reserves space for 10 elements
```
## Anonymous structure
```c
union WordByte
{
	short w;
	struct { char b1, b1 }; // Anonymous structure
};
union WordByte wb = {256};
char lowByte = wb.b0;
```
## _Static_assert
```c
// Only an instruction to the compiler to test an assertion.
_Static_assert(sizeof(int)>2, "16-bit code not supported");
// static_assert (assert.h)
```

## Storage Classes
| Storage Speciflier | Storage | Initial value | Scope | Life |
| - | - | - | - | - |
| auto | stack | Garbage | Within block | End of block |
| extern | Data segment | Zero | global Multiple files | Till end of program |
| static | Data segment | Zero | Within block | Till end of program |
| register | CPU Register | Garbage | Within block | End of block |
```c
int x; // Zero
void foo()
{
	static int y; // Zero
	int z; // Garbage
}
```

## F() and F(void)
```c
void func1() {}
void func2(void) {}

void main()
{
	fun1(10, "abc", -1.0f); // Compile and runs fine
	fun2(10, "abc", -1.0f); // Fails in compilation
}
```
## Executed before and after main
```c
// With GCC family of C compilers
void myStartupFun (void) __attribute__ ((constructor)); // executed before main()
void myCleanupFun (void) __attribute__ ((destructor)); // executed after main()
```
