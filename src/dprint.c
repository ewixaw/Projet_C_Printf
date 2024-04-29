/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 15:36 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: printf function
 */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "dprint.h"

static int is_format(char option)
{
    char *wanted;
    int cnt;

    cnt = 0;
    wanted = "csdpbxo%";
    while (cnt < stu_strlen(wanted)) {
        if (wanted[cnt] == option) {
            return (0);
        }
        cnt = cnt + 1;
    }
    return (1);

}

static int print_to(const char *msg, char **options)
{
    int cnt;
    int cnt2;

    cnt = 0;
    while (msg[cnt] != '\0') {
        if (msg[cnt] == '%') {
            cnt2 = cnt + 1;
            while (msg[cnt2] != '\0' && is_format(msg[cnt2])) {
                cnt2 = cnt2 + 1;
            }
            cnt2 = cnt2 - cnt - 1;
            *options = malloc(sizeof(char) * (cnt2 + 1));
            stu_strcpy(*options, &msg[cnt + 1], cnt2);
            return (cnt);
        }
        cnt = cnt + 1;
    }
    return (cnt);
}

const struct printf_table_row PRINTF_TABLE[] = {
    {'c', print_c},
    {'s', print_s},
    {'d', print_d},
    {'p', print_p},
    {'b', print_b},
    {'o', print_o},
    {'x', print_x},
    {'%', print_pour},
};

const unsigned int PRINTF_TABLE_LEN =
    sizeof(PRINTF_TABLE) / sizeof(struct printf_table_row);

static int process(va_list *liste, char var, int fd, char *options)
{
    unsigned int cnt;

    cnt = 0;
    while (cnt < PRINTF_TABLE_LEN) {
        if (PRINTF_TABLE[cnt].name == var) {
            return (PRINTF_TABLE[cnt].fptr(liste, options, fd));
        }
        cnt = cnt + 1;
    }
    return (write(fd, options, stu_strlen(options)));
}

int stu_dprintf(int fd, const char *pattern, ...)
{
    va_list list;
    char *options;
    int cnt;
    int len;
    int res;

    va_start(list, pattern);
    cnt = 0;
    res = 0;
    while (pattern[cnt] != '\0') {
        len = print_to(&pattern[cnt], &options);
        res = res + write(fd, &pattern[cnt], len);
        cnt = cnt + len;
        if (pattern[cnt] == '%') {
            res = res + process(&list, pattern[cnt + stu_strlen(options) + 1],
                                fd, options);
            cnt = cnt + stu_strlen(options) + 1;
            if (pattern[cnt] != '\0') {
                cnt = cnt + 1;
            }
            free(options);
        }
    }
    va_end(list);
    return (res);
}
