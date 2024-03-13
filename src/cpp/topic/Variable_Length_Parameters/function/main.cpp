#include <iostream>
#include <stdarg.h> // for va_list, va_start, va_arg, va_end

int myprintf(const char *format, ...)
{
    int len = 0;
    va_list args;           // initialize the argument list
    va_start(args, format); // set the first argument after format

    while (*format != '\0')
    {
        if (*format == '%')
        {
            switch (*++format)
            {
            case 'd':
                std::cout << va_arg(args, int);
                len += 1;
                break;
            case 's':
                std::cout << va_arg(args, char *);
                len += 1;
                break;
            default:
                std::cout << *format;
                len += 1;
                break;
            }
        }
        else
        {
            std::cout << *format;
            len += 1;
        }
        format++;
    }

    va_end(args); // clean up the argument list
    return len;
}

int main()
{
    myprintf("my name is %s, age is %d \n", "John", 25);
    return 0;
}