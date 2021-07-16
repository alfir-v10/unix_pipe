#include "pipex.h"

void	ft_input_fd(t_pipex *pipex)
{
    if ((pipex->input_fd = open(pipex->file1, O_RDONLY, S_IRWXU)) < 0)
    {
        perror("Read error");
        exit(1);
    }
    dup2(pipex->input_fd, 0);
}