/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 16:41 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_base function
 */

#include <stdarg.h>
#include <unistd.h>
#include "dprint.h"

static int signe(long *number)
{
    if (*number < 0) {
        write(1, "-", 1);
        *number = *number * -1;
        return (1);
    }
    return (0);
}

static int taille(long number, int len_base)
{
    int len;

    len = 0;
    while (number != 0) {
        number = number / len_base;
        len = len + 1;
    }
    return (len);
}

static char get_digit(long number, int cnt, char *base, int len_base)
{
    while (cnt != 0) {
        number = number / len_base;
        cnt = cnt - 1;
    }
    return (base[number % len_base]);
}

int print_base(long number, char *base, int fd)
{
    int len;
    int len_base;
    int nb_printed;
    int cnt;
    char c;

    if (number == 0) {
        c = base[0];
        write(1, &c, 1);
        return (1);
    }
    len_base = stu_strlen(base);
    len = taille(number, len_base);
    nb_printed = signe(&number);
    while (len != 0) {
        cnt = len - 1;
        c = get_digit(number, cnt, base, len_base);
        write(fd, &c, 1);
        len = len - 1;
        nb_printed = nb_printed + 1;
    }
    return (nb_printed);
}
