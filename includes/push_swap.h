#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"
# define DEBUG 0
# define SIZE 11500
typedef struct s_stack
{
	int			n;
	struct s_stack *next;
}				t_stack;


//OPERATIONS
void		swap(t_stack **a);
void		rotate(t_stack **a);
void		reverse_rotate(t_stack **a);
void		push(t_stack **a, t_stack **b);


//UTILS
t_stack 	*last_stack(t_stack *head);
t_stack 	*build_stack(char **av);
void		print_error(t_stack *head, char *msg);
t_stack		*create_node(int n);
void		add_stack(t_stack **head, t_stack *new);
void		free_stack(t_stack *head);
int			get_size(t_stack *a);
int			is_ascending(t_stack *a);
void    	print_stack(t_stack *a, t_stack *b);
int			is_descending(t_stack *b);

//PUSH_SWAP
int			get_biggest(t_stack *a);
int			get_smallest(t_stack *a);
void		tiny_sort(t_stack **a, char *instructions);
int			quicksort(t_stack **a, t_stack **b);
void		optimize(char *op);
void		huge_sort(t_stack **a, t_stack **b, char *instructions);
void			medium_sort(t_stack **a, t_stack **b, char *instructions);
int			find_position(t_stack *s, int n);

#endif