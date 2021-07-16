#include "pipex.h"

void	ft_pipe_close(t_list *cmd)
{
    t_list	*tmp;

    tmp = cmd;
    while (tmp)
    {
        if (tmp->next)
        {
            close(((t_cmd *)tmp->data)->pipe_fd[0]);
            close(((t_cmd *)tmp->data)->pipe_fd[1]);
        }
        tmp = tmp->next;
    }
}