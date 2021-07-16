#include "pipex.h"

static char	*get_env_parser(char **env)
{
    int	i;

    i = 0;
    while (env[i])
    {
        if (!ft_strncmp("PATH=", env[i], 5))
            return (env[i] + 5);
        i++;
    }
    return (NULL);
}

char	*ft_path_parser(char *bin, char **env)
{
    char	*path;
    char	*binpath;
    char	**pth;
    int		i;

    path = get_env_parser(env);
    pth = ft_split(path, ':');
    i = -1;
    while (pth && pth[++i])
    {
        pth[i] = ft_strapp(pth[i], '/');
        binpath = ft_strjoin(pth[i], bin);
        if (open(binpath, O_RDONLY) > 0)
        {
            ft_free2(pth);
            free(bin);
            return (binpath);
        }
        free(binpath);
    }
    if (pth)
        ft_free2(pth);
    return (bin);
}