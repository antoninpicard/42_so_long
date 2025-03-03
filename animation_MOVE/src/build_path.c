#include <stdlib.h>

static void    my_strcpy(char *dest, const char *src)
{
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

static void    my_strcat(char *dest, const char *src)
{
    while (*dest)
        dest++;
    my_strcpy(dest, src);
}

static void    my_itoa(int num, char *str)
{
    int     i;
    int     j;
    char    temp[10];

    i = 0;
    if (num == 0)
        str[i++] = '0';
    while (num > 0)
    {
        temp[i++] = (num % 10) + '0';
        num /= 10;
    }
    j = 0;
    while (j < i)
    {
        str[j] = temp[i - j - 1];
        j++;
    }
    str[j] = '\0';
}

void    build_frame_path(char *buffer, const char *folder, int frame_number)
{
    char    frame_str[10];

    my_strcpy(buffer, "textures/");
    my_strcat(buffer, folder);
    my_strcat(buffer, "/frame_");
    my_itoa(frame_number, frame_str);
    my_strcat(buffer, frame_str);
    my_strcat(buffer, ".xpm");
}
