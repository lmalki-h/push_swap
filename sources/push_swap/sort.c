#include "../../includes/push_swap.h"

/*
**	Sort stacks of 2-3 numbers in ascending order 
*/
void	tiny_sort(t_stack **a, char *instructions)
{
	int		smallest;
	int		biggest;

	biggest = get_biggest(*a);
	smallest = get_smallest(*a);
	if ((*a)->n == biggest && (*a)->next->n == smallest)
	{
		rotate(a);
		ft_strlcat(instructions, "ra\n", SIZE);
	}
	else if ((*a)->n != smallest && (*a)->next->n == biggest)
	{
		reverse_rotate(a);
		ft_strlcat(instructions, "rra\n", SIZE);
	}
	else
	{
		swap(a);
		ft_strlcat(instructions, "sa\n", SIZE);
	}
	print_stack(*a, NULL);
}

void		medium_sort(t_stack **a, t_stack **b, char *instructions)
{
	// (void)instructions;
	(void)b;
	int sorted = 0;
	int size = get_size(*a);
	while (!is_ascending(*a))
	{
		t_stack *tmp = *a;
		int i = 0;
		while (i < sorted)
		{
			tmp = tmp->next;
			i++;
		}						//get the smallest number from the unsorted pile
		int smallest = get_smallest(tmp);
		int small_pos = find_position(*a, smallest);

		// printf("smallest = %i position %i\n", smallest, small_pos);
		// printf("number sorted = %i\n", sorted);
		// sleep(1);
		if (small_pos != sorted && small_pos < (size / 2))
		{
			i = 0;
			while (i < sorted) //on push les nombres deja triés en bas pour les preserver
			{
				rotate(a);
				ft_strlcat(instructions, "ra\n", SIZE);

				print_stack(*a, NULL);
				i++;
			}
			i = 0;
			while (i < small_pos - sorted)
			{
				rotate(a);
				ft_strlcat(instructions, "ra\n", SIZE);

				print_stack(*a, NULL);
				i++;
			}
			i = 0;
			while (i < small_pos - sorted)
			{
				reverse_rotate(a);
				ft_strlcat(instructions, "rra\n", SIZE);
				print_stack(*a, NULL);
				if ((*a)->n > (*a)->next->n)
				{
							swap(a);
							ft_strlcat(instructions, "sa\n", SIZE);

				}
				print_stack(*a, NULL);
				i++;
			}
			i = 0;
			while (i < sorted)
			{
				reverse_rotate(a);
				ft_strlcat(instructions, "rra\n", SIZE);

				print_stack(*a, NULL);
				i++;

			}
			// printf("I should be back at my top\n");
			// sleep(10);
			print_stack(*a, NULL);
		}
		else if (small_pos != sorted)
		{
			// printf("smallest is closer to bottom\n");
			// sleep(1);
			i = 0;
			while (i < size - small_pos) //on push les nombres deja triés en bas pour les preserver
			{
				reverse_rotate(a);
				ft_strlcat(instructions, "rra\n", SIZE);

				print_stack(*a, NULL);
				i++;
			}
			// printf("smallest should be at the top\n");
			// sleep(4);
			i = 0;
			while (sorted && i < small_pos - sorted)
			{
				reverse_rotate(a);
				ft_strlcat(instructions, "rra\n", SIZE);

				print_stack(*a, NULL);
				if ((*a)->n > (*a)->next->n)
				{
									swap(a);
					ft_strlcat(instructions, "sa\n", SIZE);
				}
				print_stack(*a, NULL);
				i++;
			}
			// printf("current number should follow sorted number\n");
			// sleep(4);
			i = 0;
			while (i < sorted)
			{
				reverse_rotate(a);
				ft_strlcat(instructions, "sa\n", SIZE);

				print_stack(*a, NULL);
				i++;
			}	
			// printf("smallest should be at the top\n");
			// i = 0;
			// while (i < small_pos - sorted)
			// {
			// 	reverse_rotate(a);
			// 	print_stack(*a, NULL);
			// 	if ((*a)->n > (*a)->next->n)
			// 		swap(a);
			// 	print_stack(*a, NULL);

			// 	i++;
			// }
			// i = 0;
			// while (i < sorted)
			// {
			// 	reverse_rotate(a);
			// 	print_stack(*a, NULL);
			// 	i++;

			// }
			// printf("smallest = %i was at position small_pos %i now at pos %i and %i are sorted\n", smallest, small_pos, find_position(*a, smallest), sorted);
			// // sleep(5);
			print_stack(*a, NULL);
		}
		sorted++;
	}

}


/*
**	A sort of reimplementation of quicksort
*/
void	huge_sort(t_stack **a, t_stack **b, char *instructions)
{
	int i;
	int smallest;
	int biggest;
	int pivot;
	int size;

	smallest = get_smallest(*a);
	biggest = get_biggest(*a);
	pivot = (smallest + biggest) / 2 * 1.5;
	printf("smallest = %i biggest %i et pivot = %i\n", smallest, biggest, pivot);
	sleep(5);
	i = 0;
	size = get_size(*a);
	while (get_size(*a) > size / 2)
	{
		if (i < size)
		{
			if ((*a)->n < pivot)
			{
				push(a, b);
				ft_strlcat(instructions, "pb\n", SIZE);
			}
			else
			{
				rotate(a);
				ft_strlcat(instructions, "ra\n", SIZE);
			}
			i++;
		}
		else
		{
			i = 0;
			pivot /= 1.5;
		}
	}
	medium_sort(a, b, instructions);
}