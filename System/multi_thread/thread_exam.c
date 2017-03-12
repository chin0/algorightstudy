#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void * start_thread(void *message)
{
    printf("%s\n",(const char *)message);
    return message;
}

int main(void)
{
    pthread_t thing1,thing2;
    const char *message1 = "Thing 1:";
    const char *message2 = "Thing 2:";

    pthread_create(&thing1,NULL,start_thread,(void*)message1);
    pthread_create(&thing2,NULL,start_thread,(void*)message2);

    //스레드 종료때까지 대기(메인 스레드가 먼저 종료될수 있음.)
    
    pthread_join(thing1,NULL);
    pthread_join(thing2,NULL);
    return 0;
}
    
