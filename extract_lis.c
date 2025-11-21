/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_lis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 17:14:50 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/21 18:25:33 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* print stack A to verify LIS order */
static void	print_stack_a_lis(t_node *a)
{
	printf("[DEBUG] A after extract_lis (only LIS nodes): ");
	while (a)
	{
		printf("%d(index=%d) ", a->value, a->index);
		a = a->next;
	}
	printf("\n");
}

/*
** extract NON-LIS nodes to B while keeping LIS nodes
** in exactly the same relative order they appear in A.
*/
void	extract_lis(t_node **a, t_node **b, int *lis, int lis_len)
{
	int	i;
	int	target;

	if (!a || !*a)
		return ;

	i = 0;
	target = lis[i];
		while (i < lis_len)
	{
		if ((*a)->index == target)
		{
			/* keep this LIS node in A */
			printf("ra: keeping LIS %d (%d)\n", (*a)->value, target);
			ra(a);
			i++;
			if (i < lis_len)
				target = lis[i];
		}
		else
		{
			printf("pb: moving %d to B (not LIS)\n", (*a)->value);
			pb(a, b);
		}
	}

	/* print A after extraction so we can verify correctness */
	print_stack_a_lis(*a);
}
