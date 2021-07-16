#include "pipex.h"

int	ft_empty_check(const char *str)
{
    int	i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (str[i])
        return (0);
    return (1);
}