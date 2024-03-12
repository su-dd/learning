#include <iostream>
#include <stdarg.h> // for va_list, va_start, va_arg, va_end

int testparams(int count, ...)
{
    va_list args;
    va_start(args, count); // initialize the argument list
    for (int i = 0; i < count; ++i)
    {
        int arg = va_arg(args, int); // get the next argument
        printf("arg %d = %d \n", i, arg);
    }
    va_end(args); // clean up the argument list
    return 0;
}

int main()
{
    testparams(3, 1, 2, 3);
    return 0;
}