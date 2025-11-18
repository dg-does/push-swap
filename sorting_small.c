/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:39:40 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/18 16:09:21 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *head)
{
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

static void	sort_two(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if ((x > y) && (y < z) && (x < z))
		sa(a);
	else if ((x > y) && (y > z))
	{
		sa(a);
		rra(a);
	}
	else if ((x > y) && (y < z) && (x > z))
		ra(a);
	else if ((x < y) && (y > z) && (x < z))
	{
		sa(a);
		ra(a);
	}
	else if ((x < y) && (y > z) && (x > z))
		rra(a);
}

void	sort_small(t_node **a, t_node **b)
{
	int	size; 

	size = list_size(*a);
	if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
	{
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
	}
	else if (size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		sort_three(a);
		pa(a, b);
		pa(a, b);
	}
}
