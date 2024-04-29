/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-16 - 16:54 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: stu_strlen function
 */

int stu_strlen(char *msg)
{
    int cnt;

    cnt = 0;
    while (msg[cnt] != '\0') {
        cnt = cnt + 1;
    }
    return (cnt);
}
