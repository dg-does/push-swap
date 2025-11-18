/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:38:28 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/18 16:09:37 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	median_partition(t_node **a, t_node **b)
{
	int	size;
	int	median;
	int	processed;
	int	pushed;

	size = list_size(*a);
	median = get_median(*a, size);
	processed = 0;
	pushed = 0;
	while (processed < size)
	{
		if ((*a)->value < median)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		processed++;
	}
	if (pushed == 0 && *a)
		pb(a, b);
}

static void	push_back_sorted(t_node **a, t_node **b)
{
	while (*b)
		push_max_to_a(a, b);
}

static void	push_swap(t_node **a)
{
	t_node	*b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	if (list_size(*a) <= 5)
	{
		sort_small(a, &b);
		return ;
	}
	while (list_size(*a) > 3)
		median_partition(a, &b);
	sort_three(a);
	push_back_sorted(a, &b);
}

int	main(int argc, char **argv)
{
	t_node	*stack;

	if (argc < 2)
		return (0);
	stack = stack_init(argc, argv);
	if (!stack)
		return (1);
	push_swap(&stack);
	free_list(stack);
	return (0);
}

