/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 17:09 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_pour function
 */

#include <unistd.h>
#include <stdarg.h>

int print_pour(va_list *liste, char *options, int fd)
{
    (void) liste;
    (void) options;
    return (write(fd, "%", 1));
}
