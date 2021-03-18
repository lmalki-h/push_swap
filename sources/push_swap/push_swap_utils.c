#include "../../includes/push_swap.h"

void	move_down(t_stack **s, int index, char *instructions)
{
	int i;
	int moves;

	i = 0;
	moves = get_size(*s) - index;
	while (i++ < moves)
	{
		reverse_rotate(s);
		ft_strlcat(instructions, "ra\n", SIZE);

	}
	i = 0;
	while (++i < moves)
	{
		swap(s);
		ft_strlcat(instructions, "sa\n", SIZE);
		rotate(s);
		ft_strlcat(instructions, "ra\n", SIZE);

	}
}

void	move_up(t_stack **s, int moves, char *instructions)
{
	int i;

	i = 0;
	while (i++ < moves)
	{
		rotate(s);
		ft_strlcat(instructions, "ra\n", SIZE);
	}
	i = 0;
	while (i++ < moves)
	{
		reverse_rotate(s);
		ft_strlcat(instructions, "rra\n", SIZE);
		swap(s);
		ft_strlcat(instructions, "sa\n", SIZE);

	}
}

int		find_position(t_stack *s, int n)
{
	int 	position;
	t_stack *tmp;

	tmp = s;
	position = 0;
	while (tmp && tmp->n != n)
	{
		position++;
		tmp = tmp->next;
	}
	return position;
}

int		get_biggest(t_stack *a)
{
	int biggest;
	t_stack *tmp;

	tmp = a;
	biggest = a->n;
	while (tmp != NULL)
	{
		if (biggest < tmp->n)
			biggest = tmp->n;
		tmp = tmp->next;
	}
	return (biggest);
}

int		get_smallest(t_stack *a)
{
	int smallest;
	t_stack *tmp;

	tmp = a;
	smallest = a->n;
	while (tmp != NULL)
	{
		if (smallest > tmp->n)
			smallest = tmp->n;
		tmp = tmp->next;
	}
	return (smallest);
}
