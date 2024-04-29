/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 16:20 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_s function
 */

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include "dprint.h"

int print_s(va_list *liste, char *options, int fd)
{
    char *msg;

    (void) options;
    msg = va_arg(*liste, char *);
    if (msg == NULL) {
        return (write(fd, "(null)", 6));
    }
    return (write(fd, msg, stu_strlen(msg)));
}
