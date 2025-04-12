#include <unistd.h>
#include <stdio.h>

int char_to_int(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    if (c >= 'a' && c <= 'f')
        return (c - 'a' + 10);
    if (c >= 'A' && c <= 'F')
        return (c - 'A' + 10);
    return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int idx = 0;
    int r = 0, s = 1;

    while(str[idx] == ' ' || str[idx] == '\f' || str[idx] == '\n' || str[idx] == '\r' || str[idx] == '\t' || str[idx] == '\v')
    {
        idx++;
    }
    if (str[idx] == '-' || str[idx] == '+')
    {
        if (str[idx] == '-')
            s = -1;
        idx++;
    }
    while (str[idx] != '\0' && char_to_int(str[idx]) != -1)
    {
        r = r * str_base + char_to_int(str[idx]);
        idx++;
    }
    return (s * r);
}

int main(void)
{

    printf("%d\n", ft_atoi_base("100110", 2));

    return 0;
}
