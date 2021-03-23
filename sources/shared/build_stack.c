#include "../../includes/push_swap.h"

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