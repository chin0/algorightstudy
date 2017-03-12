#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>

int main(void)
{
    int policy;
    struct sched_param sp = {.sched_priority = 1}; //프로세스 우선순위
    int ret;

    ret = sched_setscheduler(0,SCHED_RR,&sp);//스케줄러설정
    
    if(ret == -1){
        perror("sched_setscheduler");
        return 0;
    }
    /*현재 프로세스의 스케줄링 정책을 얻어옴*/
    policy = sched_getscheduler(0);

    switch(policy){
        case SCHED_OTHER:
            printf("Policy is normal\n");
            break;
        case SCHED_FIFO:
            printf("Policy is FIFO\n");
            break;
        case SCHED_RR:
            printf("Policy is round-robin\n");
            break;
        case -1:
            perror("sched_getscheduler");
            break;
        default:
            fprintf(stderr,"Unknown plicy\n");
    }
    ret = sched_getparam(0,&sp); //get scheduling param
    if(ret == -1){
        perror("sched_getparam");
        return 1;
    }
    printf("Our priorty is %d\n",sp.sched_priority);
    
    printf("set our priorty to 2.\n");
    sp.sched_priority = 2;
    ret = sched_setparam(0,&sp); //set scheduling param 
    if(ret == -1){
        perror("sched_setparam");
        return 1;
    }
    ret = sched_getparam(0,&sp); //get scheduling param
    if(ret == -1){
        perror("sched_getparam");
        return 1;
    }
    printf("Our priorty is %d\n",sp.sched_priority);
    return 0;
}

