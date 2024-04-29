/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-20 - 14:36 +0100
 * 1st author:  tony.yam - tony.yam
 * description: print_plus function
 */

#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include "dprint.h"

static int finals_d(va_list *liste, int fd)
{
    int vl;

    vl = va_arg(*liste, int);
    if (vl > 0) {
        write(fd, "+", 1);
        return (print_base10(vl, fd) + 1);
    }
    return (print_base10(vl, fd));
}

const struct printf_table_row PRINTF_TABLE2[] = {
    {'d', finals_d},
    {'b', print_b},
    {'o', print_o},
    {'x', print_x},
};

const unsigned int PRINTF_TABLE_LEN2 =
    sizeof(PRINTF_TABLE2) / sizeof(struct printf_table_row);

int print_plus(va_list *liste, char lettre, int fd)
{
    unsigned int cnt;

    cnt = 0;
    while (cnt < PRINTF_TABLE_LEN2) {
        if (PRINTF_TABLE2[cnt].name == lettre) {
            return (PRINTF_TABLE2[cnt].fptr(liste, fd));
        }
        cnt = cnt + 1;
    }
    write(fd, "\nformat error\n", 14);
    return (0);
}
