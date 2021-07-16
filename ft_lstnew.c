#include "pipex.h"

t_list	*ft_lstnew(void *data)
{
    t_list	*new_list;

    new_list = malloc(sizeof(t_list));
    if (!new_list)
        return (NULL);
    new_list->data = data;
    new_list->next = NULL;
    new_list->prev = NULL;
    return (new_list);
}
