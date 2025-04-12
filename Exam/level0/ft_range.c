#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int count_size(int start, int end)
{
    int count = 0;
    if (start <= end)
    {
        while (start <= end)
        {
            count++;
            start++;
        }
        return (count);
    }
    while (end <= start)
    {
        count++;
        end++;
    }
    return (count);
}

int     *ft_range(int start, int end)
{
    int size = count_size(start, end);
    int idx = 0;
    int     *arr;
    arr = malloc(size * sizeof(int));
    if (start <= end)
    {
        while (idx < size)
        {
            arr[idx] = start;
            start++;
            idx++;
        }
        return (arr);
    }
    while (idx < size)
    {
        arr[idx] = start;
        start--;
        idx++;
    }
    return (arr);
}


int main(void)
{
    int *tab;

    tab = ft_range(0, -3);
    int idx = 0;
    while (idx <= 10)
    {
        printf("%d ", tab[idx]);
        idx++;
    }
    return 0;
}