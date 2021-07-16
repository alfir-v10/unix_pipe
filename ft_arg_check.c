#include "pipex.h"

void	ft_arg_check(int ac, char **arg)
{
    int	i;

    i = 0;
    while (i < ac)
    {
        if (ft_empty_check(arg[i]))
        {
            ft_putstr("Argument Missed");
            exit(1);
        }
        i++;
    }
}