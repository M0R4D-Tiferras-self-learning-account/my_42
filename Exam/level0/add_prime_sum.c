#include <unistd.h>
#include <stdio.h>

int     is_prime(int num)
{
    if (num < 2)
        return (-1);
    if (num == 2 || num == 3)
        return (1);
    int it = 2;
    while ((it * it) <= num)
    {
        if (num % it == 0)
            return (-1);
        it++;
    }
    return (1);
}

