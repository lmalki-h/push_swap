#include "../../includes/push_swap.h"

static void	execute(char *op, t_stack **a, t_stack **b)
{
	if (op[2] != '\0')
	{
		if (op[2] != 'a')
			reverse_rotate(b);
		if (op[2] != 'b')
			reverse_rotate(a);
	}
	else if (op[0] == 's')
	{
		if (op[1] != 'a')
			swap(b);
		if (op[1] != 'b')
			swap(a);
	}
	else if (op[0] == 'r')
	{
		if (op[1] != 'a')
			rotate(b);
		if (op[1] != 'b')
			rotate(a);
	}
	else if (op[0] == 'p')
		op[1] != 'a' ? push(a, b) : push(b, a);
}

void	check(t_lst *lst, t_stack *a)
 {
	 t_lst *tmp;
	t_stack *b;

	b = NULL;
	while (lst != NULL)
	{
		tmp = lst->next;
		execute(lst->content, &a, &b);
		free(lst);
		lst = tmp;
	}
	if (is_increasing(a) && !b)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
 }
