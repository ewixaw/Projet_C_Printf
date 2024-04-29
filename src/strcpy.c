/*
 * E89 Pedagogical & Technical Lab
 * project:     2023_printf
 * created on:  2024-02-28 - 14:54 +0100
 * 1st author:  maxime.franchomme - maxime.franchomme
 * description: strcpy function
 */

char *stu_strcpy(char *dest, const char *src, int size)
{
    int counter;

    counter = 0;
    while (src[counter] != '\0' && counter < size) {
        dest[counter] = src[counter];
        counter = counter + 1;
    }
    dest[counter] = '\0';
    return (dest);
}
