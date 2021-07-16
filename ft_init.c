#include "pipex.h"

static t_cmd	*ft_cmd(char *s, char **env)
{
    t_cmd	*cmd;

    if (!(cmd = malloc(sizeof(t_cmd))))
    {
        perror("Error: malloc cmd");
        return (NULL);
    }
    cmd->arg = ft_split(s, ' ');
    cmd->bin = ft_path_parser(ft_strdup(cmd->arg[0]), env);
    cmd->pipe_fd[0] = -1;
    cmd->pipe_fd[1] = -1;
    return (cmd);
}

void	ft_init(int args, char **argv, t_pipex *pipex)
{
    int		i;
    t_cmd	*cmd;

    pipex->cmd = NULL;
    ft_arg_check(args, argv);
    pipex->file1 = ft_strdup(argv[1]);
    pipex->file2 = ft_strdup(argv[args - 1]);
    i = 1;
    while (argv[++i] && (i < args - 1))
    {
        cmd = ft_cmd(argv[i], pipex->env);
        ft_lstadd_back(&(pipex->cmd), ft_lstnew(cmd));
    }
}