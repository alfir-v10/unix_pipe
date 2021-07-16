#include "pipex.h"

static void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void		ft_putstr(char *str)
{
    int st;

    st = 0;
    while (str[st] != '\0')
    {
        ft_putchar(str[st]);
        st++;
    }
}