#include "main.h"

/**
 * 
 * 
*/

int _printf(const char *format, ...)
{
    int num;
    num = 0;

    va_list list;
    va_start(list, format);
    
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    num += _putchar(va_arg(list, int));
                    break;
                case 's':
                    num += _printf(va_arg(list, char*));
                    break;
                case '%':
                    num += _putchar('%');
                    break;
            }
        } else {
            num += _putchar(*format);
        }
        format++;
    }
    va_end(list);
    return num;
}

