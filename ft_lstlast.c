#include "pipex.h"

t_list	*ft_lstlast(t_list *list)
{
    if (list)
        while (list->next)
            list = list->next;
    return (list);
}