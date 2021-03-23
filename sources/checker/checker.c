#include "../../includes/push_swap.h"

static bool is_valid_instruction(char *s)
{
	char	*instructions[NB_INSTRUCTIONS];
	int		i;

	i = 0;
	instructions[0] = "pa";
	instructions[1] = "pb";
	instructions[2] = "ra";
	instructions[3] = "rb";
	instructions[4] = "rr";
	instructions[5] = "rra";
	instructions[6] = "rrb";
	instructions[7] = "rrr";
	instructions[8] = "sa";
	instructions[9] = "sb";
	instructions[10] = "ss";
	while (i < NB_INSTRUCTIONS)
	{
		if (strcmp(instructions[i], s) == 0)
			return (true);
		i++;
	}
	return (false);
}

static bool check_instruction(t_lst *lst)
{
	t_lst *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		if (!is_valid_instruction(tmp->content))
		{
			return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}

t_lst	*get_instructions(void)
{
	t_lst 	*head;
	t_lst	*new;
	char	*line;

	head = NULL;
	while (1)
	{
		get_next_line(STDIN_FILENO, &line);
		if (!line)
			break ;
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
		if (!check_instruction(lst))
		{
			free_lst(lst);
			exit_error(a);
		}
		if (!a)
		{
			exit_error(NULL);
		}
		check(lst, a);
	}
	return (0);
}
