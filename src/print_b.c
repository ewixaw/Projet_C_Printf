/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 16:39 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_b function
 */

#include <unistd.h>
#include <stdarg.h>
#include "dprint.h"

int print_b(va_list *liste, char *options, int fd)
{
    int vl;

    (void) options;
    vl = va_arg(*liste, int);
    return (print_base(vl, "01", fd));
}
