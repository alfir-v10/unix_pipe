#include "pipex.h"

void    ft_wait(t_pipex *pipex)
{
    ft_pipe_close(pipex->cmd);
    waitpid(pipex->pid, &(pipex->status), 0);
    pipex->status = WEXITSTATUS(pipex->status);
    while (wait(NULL) > 0)
        ;
}