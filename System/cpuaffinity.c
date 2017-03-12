#define _GNU_SOURCE
#include <stdio.h>
#include <error.h>
#include <sched.h>

int main(void)
{
    cpu_set_t set;
    int ret,i;

    CPU_ZERO(&set);
    CPU_SET(0,&set); //cpu #0은 허용한다.
    CPU_CLR(1,&set); //cpu #1은 허용하지않는다.
    ret = sched_getaffinity(0,sizeof(cpu_set_t),&set);
    if(ret == -1)
        perror("sched_getaffinity");

    for(i=0;i< __CPU_SETSIZE;i++) //내 cpu는 듀얼코어니까 #0과 #1번만
    {
        int cpu;
        cpu = CPU_ISSET(i,&set);
        printf("cpu=%i is %s\n",i,
                cpu ? "set" : "unset");
    }
    //이 프로그램은 오직 CPU #0에서만
    return 0;
}
