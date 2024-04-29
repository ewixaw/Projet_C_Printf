/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 16:15 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_c function
 */

#include <unistd.h>
#include <stdarg.h>

int print_c(va_list *liste, char *options, int fd)
{
    int vl;

    (void) options;
    vl = va_arg(*liste, int);
    return (write(fd, &vl, 1));
}
