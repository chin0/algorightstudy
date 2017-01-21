#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/fs.h>
int main(void)
{
    pid_t pid;
    int i;
    //new process
    pid = fork();
    if(pid == -1)
        return -1;
    else if(pid != 0) //kill parent process
        exit(EXIT_SUCCESS);
    
    //new session and new process group.
    if(setsid() == -1)
        return -1;
    //change directory
    if(chdir("/") == -1)
        return -1;
    //close all file descriptor
    for(i=0;i < NR_OPEN;i++)
        close(i);
    //stdin,stdout,stderr > /dev/null
    open("/dev/null",O_RDWR);//stdin
    dup(0); //stdout
    dup(0);//stderr
    
    //your code
    

    return 0;
}
