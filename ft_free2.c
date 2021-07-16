#include "pipex.h"

void	ft_free2(char **arg)
{
    int	i;

    i = 0;
    while (arg[i])
        free(arg[i++]);
    free(arg);
}
