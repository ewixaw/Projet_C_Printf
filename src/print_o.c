/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 17:05 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_o function
 */

#include <unistd.h>
#include <stdarg.h>
#include "dprint.h"

int print_o(va_list *liste, char *options, int fd)
{
    int ptr;

    (void) options;
    ptr = va_arg(*liste, int);
    return (print_base(ptr, "01234567", fd));
}
