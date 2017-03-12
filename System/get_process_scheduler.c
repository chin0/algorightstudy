#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>

int main(void)
{
    int policy;

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
}

