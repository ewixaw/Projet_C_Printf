/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 16:26 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_p function
 */

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include "dprint.h"

int print_p(va_list *liste, char *options, int fd)
{
    void *ptr;
    long vl;

    (void) options;
    ptr = va_arg(*liste, void *);
    if (ptr == NULL) {
        return (write(fd, "(nil)", 5));
    }
    vl = (long) ptr;
    write(fd, "0x", 2);
    return (print_base(vl, "0123456789abcdef", fd) + 2);
}
