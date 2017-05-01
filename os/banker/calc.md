# calc

보호기법

canary, nx,

특이사항

static compile



alarm(1m)



calc function

- 스택
  - int v1 - 
  - char s [0x400] - 
  - int v2[100]\(0x190) - result



get_expr

- 1글자씩 입력받으면서 +,-,*,%,정수인지 검사
- 맞으면 버퍼에 넣음.
- 마지막에 널바이트.

init_pool

- pool 배열 초기화