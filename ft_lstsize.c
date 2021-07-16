#include "pipex.h"

int	ft_lstsize(t_list *list)
{
    int	n;

    n = 0;
    while (list)
    {
        list = list->next;
        n++;
    }
    return (n);
}