#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

void sighandler(int);

int main()
{
    printf("Begin\n");

/*
    FILE* f = fopen("no-file.txt", "r");
    if (f == NULL)
    {
        perror("Error");
    }
    else
    {
        fclose(f);
    }

    errno = 0;
    double b = log(0.0);
    perror("New error");
*/

    signal(SIGINT, sighandler);

    while (1)
    {
        printf("Run\n");
        sleep(1);
    }


    printf("End\n");

    return 0;
}

void sighandler(int signum)
{
   printf("Caught signal %d, coming out...\n", signum);
   exit(1);
}
