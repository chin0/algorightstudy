#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int fd[2];
    int buf;
    int i=0;
    int pid;

    if(pipe(fd) < 0)
    {
        perror("pipe error: ");
        return 1;
    }

    if((pid = fork()) < 0)
        return 1;

    else if(pid == 0)
    {
        close(fd[0]);
        while(1)
        {
            i++;
            write(fd[1], (void *)&i, sizeof(i));
            sleep(1);
        }
    }

    else
    {
        close(fd[1]);
        while(1)
        {
            read(fd[0], (void*)&buf, sizeof(buf));
            printf("> %d\n",buf);
        }
    }
    return 1;
}
