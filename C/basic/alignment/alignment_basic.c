#include <stdio.h>

char c;
short s;
int i;
long l;
float f;
double d;

int main(void)
{
#define print_align(type, var)                        \
  printf(#type "\t%zd\t%zd\t%p\n", sizeof(type), __alignof__(type), &var)

  printf("type\tsize\talign\taddress\n");
  print_align(char, c);
  print_align(short, s);
  print_align(int, i);
  print_align(long, l);
  print_align(float, f);
  print_align(double, d);

  return 0;
}
