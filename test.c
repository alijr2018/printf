#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    int num_chars = 0;
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    num_chars += putchar(va_arg(args, int));
                    break;
                case 's':
                    num_chars += printf(va_arg(args, char*));
                    break;
                case '%':
                    num_chars += putchar('%');
                    break;
            }
        } else {
            num_chars += putchar(*format);
        }
        format++;
    }
    va_end(args);
    return num_chars;
}
