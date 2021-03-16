#include "../../includes/push_swap.h"

void		print_error(t_stack *head, char *msg)
{
	if (head)
		free_stack(head);
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	exit (-1);
}