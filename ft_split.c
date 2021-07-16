#include "pipex.h"

static int		counter(char const *s, char c)
{
    int n;

    n = 0;
    if (!s)
        return (0);
    while (*s)
    {
        while (*s == c && *s)
            s++;
        if (*s != c && *s)
        {
            n++;
            while (*s && *s != (char const)c)
                s++;
        }
    }
    return (n);
}

static int		clen(char const *s, char c, int i)
{
    int len;

    len = 0;
    while (s[i] && (char)s[i++] != c)
        len++;
    return (len);
}

static char		**ft_free(char **new, int n)
{
    while (n >= 0)
        free(new[n--]);
    free(new);
    return (NULL);
}

static char		**end_func(char **new, char const *s, char c, int num)
{
    int	m;
    int	n;

    m = 0;
    n = 0;
    while (s[m] && n < num)
    {
        while (s[m] == c)
            m++;
        if (s[m] && s[m] != c)
        {
            new[n] = ft_substr(s, m, clen(s, c, m));
            if (!new[n])
                return (ft_free(new, n));
            n++;
            while (s[m] && s[m] != c)
                m++;
        }
    }
    new[n] = NULL;
    return (new);
}

char			**ft_split(char const *s, char c)
{
    int		num;
    char	**new;

    num = counter(s, c);
    new = (char **)malloc((num + 1) * sizeof(char *));
    if (!new)
        return (NULL);
    new = end_func(new, s, c, num);
    return (new);
}
