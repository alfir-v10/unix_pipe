#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
    t_pipex	*pipex;

    if (argc != 5)
    {
        ft_putstr("Argument Missed");
        exit(1);
    }
    if (!(pipex = malloc(sizeof(t_pipex))))
    {
        perror("Error: malloc pipex");
        return (1);
    }
    pipex->env = env;
    ft_init(argc, argv, pipex);
    ft_pipe_open(pipex->cmd);
    ft_run_cmd(pipex);
    ft_wait(pipex);
    exit(pipex->status);
    return (pipex->status);
}