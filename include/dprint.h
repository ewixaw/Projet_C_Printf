/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 15:53 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: h file for printf project
 */

#ifndef DPRINT_H_
#define DPRINT_H_

#include <stdarg.h>

struct printf_table_row {
    char name;
    int (*fptr)(va_list *liste, char *options, int fd);
};

int stu_strlen(char *msg);
char *stu_strcpy(char *dest, const char *src, int size);
int print_base10(char *options, int nb, int fd);
int print_base(long number, char *base, int fd);
int print_c(va_list *liste, char *options, int fd);
int print_s(va_list *liste, char *options, int fd);
int print_d(va_list *liste, char *options, int fd);
int print_p(va_list *liste, char *options, int fd);
int print_b(va_list *liste, char *options, int fd);
int print_o(va_list *liste, char *options, int fd);
int print_x(va_list *liste, char *options, int fd);
int print_pour(va_list *liste, char *options, int fd);
int stu_dprintf(int fd, const char *pattern, ...);

#endif
