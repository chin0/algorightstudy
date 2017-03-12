#include <stdio.h>

#define STRINGIZE(x) #x
#define MAKE_STRING(x) STRINGIZE(x)
#define PRINT_LINE_FILE "Line " MAKE_STRING(__LINE__) ". of file" __FILE__

int main(void)
{
    printf("%s\n",PRINT_LINE_FILE);
}
