#include "libft.h"

t_lst	*ft_lstnew(void *content)
{
	t_lst	*new;

	new = (t_lst *)calloc(sizeof(t_lst), 1);
	if (!new)
		return (NULL);
	new->content = strdup(content);
	new->next = NULL;
	return (new);
}