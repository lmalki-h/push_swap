#include "../../includes/push_swap.h"

bool	is_unique(t_stack *head, double n)
{
	t_stack *tmp;
 
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->n == (int)n)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}


double		atod(char **s)
{
	double 	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*s[0] == '-' || *s[0] == '+')
	{
		if (*s[0] == '-')
			sign = -1;
		(*s)++;
	}
	while (ft_isdigit((*s)[0]))
	{
		num *= 10;
		num += (int)((*s)[0]) - '0';
		(*s)++;
	}
	return (num * (double)sign);
}

t_stack	*create_node(int n)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	new->n = n;
	return (new);
}

t_stack *last_stack(t_stack *head)
{
	t_stack *last;

	if (head)
	{
		last = head;
		while (last->next != NULL)
			last = last->next;
		return (last);
	}
	return (NULL);
}

void	add_last(t_stack **head, int n)
{
	t_stack *last;
	t_stack *new;

	new = create_node(n);
	if (!new)
		exit_error(*head);
	if (head && !*head)
		*head = new;
	else
	{
		last = last_stack(*head);
		last->next = new;
	}
}

void	parse_arguments(t_stack **head, char **av)
{
	double	n;
	char	*s;

	while (*av != NULL)
	{
		s = *av;
		while (*s != '\0')
		{
			while (*s == ' ')
				s++;
			if (*s == '-' || *s == '+' || ft_isdigit(*s))
			{
				n = atod(&s);
				if (!is_integer(n) || !is_unique(*head, n))
				{
					exit_error(*head);
				}
				add_last(head, (int)n);
			}
			else if (*s != ' ')
				exit_error(*head);
		}
		av++;
	}
}