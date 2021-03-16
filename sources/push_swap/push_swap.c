#include "../../includes/push_swap.h"

char	*push_swap(t_stack *a)
{
	char	*instructions;
	int		size;
	t_stack *b;

	b = NULL;
	instructions = (char *)ft_calloc(sizeof(char), SIZE + 1);
	if (!instructions)
		print_error(a, "Error: malloc\n");
	while (!is_ascending(a))
	{
		size = get_size(a);
		if (size < 4)
		{
			tiny_sort(&a, instructions);
		}
		else if (size < 100)
		{
			// sort_medium(&a, &b, instructions);
		}
		else
		{
			// sort_big();
		}
	}
	return (instructions);
}

int		main(int ac, char **av)
{
	t_stack *a;
	char	*instructions;

	if (ac == 1)
	{
		write(STDERR_FILENO, "Usage: ./push_swap [DIGIT ARGUMENTS]\n", 37);
	}
	else
	{
		a = build_stack(&av[1]);
		instructions = push_swap(a);
		optimize(instructions);
		if (instructions && !DEBUG)
			write(STDOUT_FILENO, instructions, ft_strlen(instructions));
	}
	return (0);
}