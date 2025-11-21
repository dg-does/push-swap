/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:38:28 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/21 18:39:44 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_node **a)
{
	t_node	*b;
	int		*lis;
	int		lis_len;
	int		size;

	b = NULL;
	size = list_size(*a);
	if (is_sorted(*a))
		return ;
	if (size <= 5)
	{
		sort_small(a, &b);
		return ;
	}
	assign_index(*a);
	lis = compute_lis_indices(*a, &lis_len);
	if (!lis)
		return ;
	mark_lis_nodes(*a, lis, lis_len);
	free(lis);
	extract_lis(a, &b);
	push_back_to_a(a, &b);
}

void    print_stack(t_node *stack)
{
    t_node *tmp = stack;

    printf("[STACK] ");

    if (!tmp)
    {
        printf("(empty)\n");
        return;
    }

    while (tmp)
    {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}//*/

int	main(int argc, char **argv)
{
	t_node	*stack;

	if (argc < 2)
		return (0);
	stack = stack_init(argc, argv);
	if (!stack)
		return (1);
	push_swap(&stack);
	print_stack(stack);
	free_list(stack);
	return (0);
}

