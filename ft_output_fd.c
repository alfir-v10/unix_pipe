#include "pipex.h"

void	ft_output_fd(t_pipex *pipex)
{
    if ((pipex->output_fd = open(pipex->file2, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU)) < 0)
    {
        perror("Write error");
        exit(1);
    }
    dup2(pipex->output_fd, 1);
}