/*
0;10;1c * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 16:22 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_d function
 */

#include <unistd.h>
#include <stdarg.h>
#include "dprint.h"

int print_d(va_list *liste, char *options, int fd)
{
    int vl;

    vl = va_arg(*liste, int);
    return (print_base10(options, vl, fd));
}
