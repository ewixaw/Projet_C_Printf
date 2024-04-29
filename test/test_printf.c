/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-20 - 15:21 +0100
 * 1st author:  tony.yam - tony.yam
 * description: test file for printf function
 */

#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "dprint.h"

Test(printf, normal_for_c) {
    char c;

    c = 'a';
    cr_redirect_stdout();
    cr_expect(eq(i32, stu_dprintf(1, "it's %c\n", c), 7));
    cr_assert_stdout_eq_str("it's a\n");
}

Test(printf, normal_for_s) {
    char *s;

    s = "world";
    cr_redirect_stdout();
    cr_expect(eq(i32, stu_dprintf(1, "hello %s\n", s), 12));
    cr_assert_stdout_eq_str("hello world\n");
}

Test(printf, normal_for_d) {
    int d;
    int n;

    d = 56;
    cr_redirect_stdout();
    cr_redirect_stderr();
    n = stu_dprintf(1, "%d\n", d);
    cr_expect(eq(i32, n, 3));
    cr_assert_stdout_eq_str("56\n");
    cr_expect(eq(i32, stu_dprintf(2, "bytes printed %d\n", n), 16));
    cr_assert_stderr_eq_str("bytes printed 3\n");
}

Test(printf, normal_for_d_and_for_exit_2) {
    int d;
    int n;

    d = 56;
    cr_redirect_stdout();
    cr_redirect_stderr();
    n = stu_dprintf(1, "%d\n", d);
    cr_expect(eq(i32, n, 3));
    cr_assert_stdout_eq_str("56\n");
    cr_expect(eq(i32, stu_dprintf(2, "bytes printed %d\n", n), 16));
    cr_assert_stderr_eq_str("bytes printed 3\n");
}

Test(printf, normal_for_p) {
    char *str;
    char *str2;

    str = "what's up !";
    str2 = malloc(sizeof(char) * 20);
    cr_redirect_stdout();
    stu_dprintf(1, "%p\n", str);
    snprintf(str2, 19, "%p\n", str);
    cr_assert_stdout_eq_str(str2);
    free(str2);
}

Test(printf, normal_for_p_NULL) {
    char *str;

    str = NULL;
    cr_redirect_stdout();
    cr_expect(eq(i32, stu_dprintf(1, "addr is %p\n", str), 14));
    cr_assert_stdout_eq_str("addr is (nil)\n");
}

Test(printf, normal_for_b_and_for_exit_2) {
    int b;
    int n;

    b = 2;
    cr_redirect_stdout();
    cr_redirect_stderr();
    n = stu_dprintf(1, "%b\n", b);
    cr_expect(eq(i32, n, 3));
    cr_assert_stdout_eq_str("10\n");
    cr_expect(eq(i32, stu_dprintf(2, "bytes printed %b\n", n), 17));
    cr_assert_stderr_eq_str("bytes printed 11\n");
}

Test(printf, normal_for_o_and_for_exit_2) {
    int o;
    int n;

    o = 56;
    cr_redirect_stdout();
    cr_redirect_stderr();
    n = stu_dprintf(1, "%o\n", o);
    cr_expect(eq(i32, n, 3));
    cr_assert_stdout_eq_str("70\n");
    cr_expect(eq(i32, stu_dprintf(2, "bytes printed %o\n", n), 16));
    cr_assert_stderr_eq_str("bytes printed 3\n");
}

Test(printf, normal_for_pour) {
    int n;

    cr_redirect_stdout();
    n = stu_dprintf(1, "%%\n");
    cr_expect(eq(i32, n, 2));
    cr_assert_stdout_eq_str("%\n");
}

Test(printf, normal_for_plus_and_negative) {
    int nb;
    int n;

    cr_redirect_stdout();
    nb = 12;
    n = stu_dprintf(1, "%+d\n", nb);
    cr_expect(eq(i32, n, 4));
    n = stu_dprintf(1, "%+o\n", nb);
    cr_expect(eq(i32, n, 3));
    n = stu_dprintf(1, "%+b\n", nb);
    cr_expect(eq(i32, n, 5));
    nb = -12;
    n = stu_dprintf(1, "%+d\n", nb);
    cr_expect(eq(i32, n, 4));
    cr_assert_stdout_eq_str("+12\n14\n1100\n-12\n");
}

Test(printf, not_expected_a) {
    int nb;
    int n;

    cr_redirect_stdout();
    nb = 2;
    n = stu_dprintf(1, "%+a\n");
    cr_expect(eq(i32, n, 3));
    n = stu_dprintf(1, "%a\n", nb);
    cr_expect(eq(i32, n, 2));
    cr_assert_stdout_eq_str("+a\na\n");
}

Test(printf, in_file) {
    char *str2;
    int fd;
    int n;

    str2 = malloc(sizeof (char) * 5);
    fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
    n = stu_dprintf(fd, "%+d\nt", 2);
    cr_expect(eq(i32, n, 4));
    close(fd);
    fd = 0;
    fd = open("test.txt", O_RDONLY);
    read(fd, str2, n);
    str2[4] = '\0';
    cr_expect(eq(i32, str2[0], '+'));
    cr_expect(eq(i32, str2[1], '2'));
    cr_expect(eq(i32, str2[2], '\n'));
    cr_expect(eq(i32, str2[3], 't'));
    free(str2);
    close(fd);
}

Test(printf, normal_for_x_and_for_exit_2) {
    int x;
    int n;

    x = 56;
    cr_redirect_stdout();
    cr_redirect_stderr();
    n = stu_dprintf(1, "%x\n", x);
    cr_expect(eq(i32, n, 3));
    cr_assert_stdout_eq_str("38\n");
    cr_expect(eq(i32, stu_dprintf(2, "bytes printed %x\n", n), 16));
    cr_assert_stderr_eq_str("bytes printed 3\n");
}
