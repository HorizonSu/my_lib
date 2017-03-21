/*
 * 字符串复制
 * 2017-3-21
 */

#include <stdio.h>

/* 函数实现 */
#if 1
char *str_copy(char *dest, const char *src)
{
    char *dst = dest;

    if (dst == NULL || src == NULL)
        return NULL;

    while ('\0' != *src)
        *dst++ = *src++;
    *dst = '\0';

    return dest;
}
#else
char *str_copy(char *dest, const char *src)
{
    register int *d4 = (int *)dest;
    register const int *s4 = (const int *)src;
    register char *d1 = NULL;
    register const char *s1 = NULL;
    register int value = *s4;

    if (dest == NULL || src == NULL)
        return NULL;

    while ((value & 0xFF000000) && (value & 0xFF0000) && (value & 0xFF00) && (value & 0xFF)) {
        *d4++ = *s4++;
        value = *s4;
    }

    d1 = (char *)d4;
    s1 = (const char *)s4;
    while ('\0' != *s1)
        *d1++ = *s1++;
    *d1 = '\0';

    return dest;
}
#endif

/* 函数测试 */
int main(int argc, const char *argv[])
{
    char dest[100] = "";

    if (argc != 2) {
        printf("Input: %s src\n", argv[0]);
        return -1;
    }

    if (str_copy(dest, argv[1]) == NULL) {
        printf("The arguments is NULL!\n");
        return -1;
    }

    printf("%s\n", dest);

    return 0;
}
