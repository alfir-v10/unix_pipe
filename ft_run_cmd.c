#include "pipex.h"

void	ft_run_cmd(t_pipex *pipex)
{
    t_list	*tmp;

    tmp = pipex->cmd;
    while (tmp)
    {
        pipex->pid = fork();
        if (!pipex->pid)
        {
            if (!tmp->prev)
                ft_input_fd(pipex);
            if (!tmp->next)
                ft_output_fd(pipex);
            ft_pipe_setup(tmp);
            if (execve(((t_cmd *)tmp->data)->bin,
                       ((t_cmd *)tmp->data)->arg, pipex->env))
            {
                perror("Execve error");
                exit(127);
            }
        }
        close(((t_cmd *)tmp->data)->pipe_fd[1]);
        if (tmp->prev)
            close(((t_cmd *)tmp->prev->data)->pipe_fd[0]);
        tmp = tmp->next;
    }
}