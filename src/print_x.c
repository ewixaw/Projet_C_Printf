/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-26 - 14:13 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print x function
 */

#include <unistd.h>
#include <stdarg.h>
#include "dprint.h"

int print_x(va_list *liste, char *options, int fd)
{
    int ptr;

    (void) options;
    ptr = va_arg(*liste, int);
    return (print_base(ptr, "0123456789abcdef", fd));
}
