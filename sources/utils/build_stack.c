#include "../../includes/push_swap.h"

/*
** Checks that n is within the INTEGER range
** and that n is unique in the stack
*/
static int		is_unique_int(t_stack *head, long n)
{
	t_stack *tmp;

	tmp = head;
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	while (tmp != NULL)
	{
		if (tmp->n == (int)n)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
**	Parse numbers and add them to stack iff unique integers
*/

static void	parse_numbers(t_stack **head, char *s)
{
	t_stack *new;
	long	n;

	while (*s != '\0')
	{
		if (ft_isdigit(*s) || *s == '-' || *s == '+') 
		{
			n = ft_atoi(s);
			if (!is_unique_int(*head, n))
				print_error(*head, "Error: invalid number\n");
			new = create_node((int)n);
			add_stack(head, new);
			while (ft_isdigit(*(s + 1)))
				s++;
		}
		else if (*s != ' ')
			print_error(*head, "Error: argument is not a number\n");
		s++;
	}
}

/*
**	Iterate throught arguments to parse numbers
*/

t_stack *build_stack(char **av)
{
	t_stack *new;

	new = NULL;
	while (*av != NULL)
	{
		parse_numbers(&new, *av);
		av++;
	}
	return new;
}