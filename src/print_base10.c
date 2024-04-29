/*
 * E89 Pedagogical & Technical Lab
 * project:     libstu
 * created on:  2024-02-05 - 09:50 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: print_base10 function
 */

#include <unistd.h>

static int nb_len(int nb)
{
    int count;

    count = 0;
    if (nb == 0) {
        return (1);
    }
    while (nb != 0) {
        nb = nb / 10;
        count = count + 1;
    }
    return (count);
}

static int get_digit(int nb, int index)
{
    int res;

    if (nb < 0) {
        nb = nb * -1;
    }
    while (index > 0) {
        nb = nb / 10;
        index = index - 1;
    }
    res = nb % 10;
    return (res);
}

static int if_plus(char *options)
{
    int cnt;

    cnt = 0;
    while (options[cnt] != '\0') {
        if (options[cnt] == '+') {
            return (1);
        }
        cnt = cnt + 1;
    }
    return (0);
}

int print_base10(char *options, int nb, int fd)
{
    int len_nb;
    int count;
    char num;

    len_nb = nb_len(nb);
    count = len_nb;
    if (nb < 0) {
        count = count + write(fd, "-", 1);
    } else if (if_plus(options)) {
        count = count + write(fd, "+", 1);
    }
    while (len_nb != 0) {
        num = '0' + get_digit(nb, len_nb-1);
        write(fd, &num, 1);
        len_nb = len_nb - 1;
    }
    return (count);
}
