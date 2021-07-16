#include "pipex.h"

void	ft_lstadd_back(t_list **list, t_list *new_list)
{
    t_list	*temp;

    temp = *list;
    if (temp)
    {
        temp = ft_lstlast(temp);
        (temp)->next = new_list;
        new_list->prev = temp;
    }
    else
        *list = new_list;
}