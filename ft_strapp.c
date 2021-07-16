#include "pipex.h"

char	*ft_strapp(char *str, char c)
{
    char	*s;
    int		len;
    int		i;

    if (!str)
    {
        if (!(s = malloc(sizeof(char) * 2)))
            return (NULL);
        s[0] = c;
        s[1] = 0;
        return (s);
    }
    len = ft_strlen(str);
    if (!(s = malloc(sizeof(char) * (len + 2))))
        return (NULL);
    i = -1;
    while (++i < len)
        s[i] = str[i];
    s[i++] = c;
    s[i] = 0;
    if (str)
        free(str);
    return (s);
}