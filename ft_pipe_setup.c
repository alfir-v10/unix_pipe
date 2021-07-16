#include "pipex.h"

void	ft_pipe_setup(t_list *cmd)
{
    if (cmd->next)
    {
        dup2(((t_cmd *)cmd->data)->pipe_fd[1], 1);
        close(((t_cmd *)cmd->data)->pipe_fd[1]);
        close(((t_cmd *)cmd->data)->pipe_fd[0]);
    }
    if (cmd->prev && cmd->next)
    {
        dup2(((t_cmd *)cmd->prev->data)->pipe_fd[0], 0);
        close(((t_cmd *)cmd->prev->data)->pipe_fd[0]);
        close(((t_cmd *)cmd->prev->data)->pipe_fd[1]);
    }
    if (cmd->prev && !cmd->next)
    {
        dup2(((t_cmd *)cmd->prev->data)->pipe_fd[0], 0);
        close(((t_cmd *)cmd->prev->data)->pipe_fd[0]);
    }
}