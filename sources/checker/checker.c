#include "../../includes/push_swap.h"

t_lst	*get_instructions(void)
{
	int		ret;
	t_lst 	*head;
	t_lst	*new;
	char	*line;

	head = NULL;
	while (1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (!line)
			break ;
		//TODO: is valid instruction
		new = ft_lstnew(line);
		ft_lstadd_back(&head, new);
	}
	return (head);
}

int		main(int ac, char **av)
{
	t_stack *a;
	t_lst	*lst;

	a = NULL;
	if (ac > 1)
	{
		parse_arguments(&a, &av[1]);
		lst = get_instructions();
		if (!a)
			exit_error(NULL);
		check(lst, a);
		if (a)
			free_stack(a);
		if (lst)
			free_lst(lst);
	}
	return (0);
}
