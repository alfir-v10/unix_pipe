#include "pipex.h"

void	ft_pipe_open(t_list *cmd)
{
    t_list	*tmp;
    int		l;

    tmp = cmd;
    l = ft_lstsize(tmp);
    while (tmp && l >= 2)
    {
        if (tmp->next)
            pipe(((t_cmd *)tmp->data)->pipe_fd);
        tmp = tmp->next;
    }
}