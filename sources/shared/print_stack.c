#include "../../includes/push_swap.h"

void    print_stack(t_stack *a, t_stack *b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    tmp_a = a;
    tmp_b = b;
    system("clear");
    printf("---- a ---    |    --- b --- \n");
    printf("-----------------------------\n");
    while (tmp_a != NULL || tmp_b != NULL)
    {
        if (tmp_a)
        {
            printf("    %i     ", tmp_a->n);
            tmp_a = tmp_a->next;
        }
        else
        {
            printf("             ");
        }
        if (tmp_b)
        {
            printf("        %i    \n", tmp_b->n);
            tmp_b = tmp_b->next;
        }
        else
            printf("\n");
    }
    sleep(1);
}
