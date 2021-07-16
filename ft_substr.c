#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t	n;
    size_t	m;
    char	*new_s;

    if (!s)
        return (NULL);
    if ((int)start > ft_strlen(s))
        return (ft_strdup(""));
    else
        m = ft_strlen(s) - (size_t)start;
    if (m < len)
        len = m;
    new_s = (char *)malloc((len + 1) * sizeof(char));
    if (!new_s)
        return (NULL);
    new_s[len] = '\0';
    n = 0;
    while (s[start] && n < len)
        new_s[n++] = s[start++];
    return (new_s);
}

