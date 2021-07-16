#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_list
{
    void			*data;
    struct s_list	*next;
    struct s_list	*prev;

}					t_list;

typedef struct s_cmd
{
    char	*bin;
    char	**arg;
    int		pipe_fd[2];
}			t_cmd;

typedef struct s_pipex
{
    t_list	*cmd;
    char	**env;
    pid_t	pid;
    char	*file1;
    char	*file2;
    int		input_fd;
    int		output_fd;
    int		status;
}			t_pipex;

int	ft_lstsize(t_list *list);
t_list	*ft_lstnew(void *data);
t_list	*ft_lstlast(t_list *list);
void	ft_lstadd_back(t_list **list, t_list *new_list);

void		ft_putstr(char *str);
int	ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
char	    *ft_strapp(char *str, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	ft_init(int args, char **argv, t_pipex *pipex);
void	ft_arg_check(int ac, char **arg);
int	    ft_empty_check(const char *str);
char	*ft_path_parser(char *bin, char **env);
void	ft_run_cmd(t_pipex *pipex);
void    ft_wait(t_pipex *pipex);

void	ft_pipe_open(t_list *cmd);
void	ft_pipe_close(t_list *cmd);
void	ft_pipe_setup(t_list *cmd);

void	ft_input_fd(t_pipex *pipex);
void	ft_output_fd(t_pipex *pipex);


void	ft_free2(char **arg);

#endif
