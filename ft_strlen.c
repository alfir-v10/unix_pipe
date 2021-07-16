#include "pipex.h"

int	ft_strlen(const char *s)
{
    int	n;

    n = 0;
    while (*s++)
        n++;
    return (n);
}