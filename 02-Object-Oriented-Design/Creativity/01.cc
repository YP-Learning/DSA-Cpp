/*
# C-2.1
Give an example of a C++ program that outputs its source code when it is
run. Such a program is called a quine.
*/
#include <cstdio>

int main()
{
    const char* str = "#include <cstdio>%c%cint main()%c{%c%cconst char* str = %c%s%c;%c%cprintf(str, 10, 10, 10, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 10);%c%creturn 0;%c}%c";
    printf(str, 10, 10, 10, 10, 9, 34, str, 34, 10, 9, 10, 9, 10, 10);
    return 0;
}
