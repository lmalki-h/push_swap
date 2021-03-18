#include "../../includes/push_swap.h"

/*
** Delete series of contradictory moves (like two consecutive swaps etc ..)
*/

void	clean(char *op)
{
	char	*parser;

	parser = op;
	while (*parser != '\0')
	{
		if (strncmp(parser, "ra\nrra\n", 7) == 0 ||
			strncmp(parser, "rra\nra\n", 7) == 0 ||
			strncmp(parser, "rb\nrrb\n", 7) == 0 ||
			strncmp(parser, "rrb\nrb\n", 7) == 0)
		{
			*parser = '\0';
			ft_strlcat(op, parser + 7, SIZE);
		}
		else if (strncmp(parser, "sa\nsa\n", 6) == 0 || 
		strncmp(parser, "sb\nsb\n", 6) == 0 || 
		strncmp(parser, "pa\npb\n", 6) == 0 || 
		strncmp(parser, "pb\npa\n", 6) == 0)
		{
			*parser = '\0';
			ft_strlcat(op, parser + 6, SIZE);
		}
		else
			parser = ft_strchr(parser, '\n') + 1;
	}
}

/*
**	Reduce two moves to one when possible (sa and sb => ss, ra and rb => rr etc)
*/

void	reduce(char *op)
{
	char	*parser;

	parser = op;
	while (*parser != '\0')
	{
		if (strncmp(parser, "sa\nsb\n", 6) == 0 ||
			strncmp(parser, "sb\nsa\n", 6) == 0)
		{
			*(parser + 1) = 's';
			*(parser + 3) = '\0';
			ft_strlcat(op, parser + 6, SIZE);
		}
		else if (strncmp(parser, "ra\nrb\n", 6) == 0 ||
			strncmp(parser, "rb\nra\n", 6) == 0 )
		{
			*(parser + 1) = 'r';
			*(parser + 3) = '\0';
			ft_strlcat(op, parser + 6, SIZE);
		}
		else if (strncmp(parser, "rra\nrrb\n", 8) == 0 ||
			strncmp(parser, "rrb\nrra\n", 8) == 0)
		{
			*(parser + 2) = 'r';
			*(parser + 4) = '\0';
			ft_strlcat(op, parser + 8, SIZE);
		}
		parser = ft_strchr(parser, '\n') + 1;
	}
}

/*
** Remove contradictions and reduce moves for efficiency
*/

void	optimize(char *op)
{
	clean(op);
	reduce(op);
}