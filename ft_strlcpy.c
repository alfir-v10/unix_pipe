#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t src_len;
    size_t n;

    n = 0;
    if (!dst || !src)
        return (0);
    src_len = ft_strlen(src);
    if (!dstsize)
        return (src_len);
    while (src[n] && n < (dstsize - 1))
    {
        dst[n] = src[n];
        n++;
    }
    dst[n] = '\0';
    return (src_len);
}