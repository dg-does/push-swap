/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimplegurajani <dimplegurajani@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 16:44:11 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/20 02:41:05 by dimpleguraj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(t_node *head)
{
	int	count;

	count = 0;
	while (head)
	{
		count++;
		head = head->next;
	}
	return (count);
}

int	find_min_pos(t_node *head)
{
	int	min;
	int	pos;
	int	i;

	if (!head)
		return (0);
	min = head->value;
	pos = 0;
	i = 0;
	while (head)
	{
		if (head->value < min)
		{
			min = head->value;
			pos = i;
		}
		head = head->next;
		i++;
	}
	return (pos);
}

void	push_min_to_b(t_node **a, t_node **b)
{
	int	pos;
	int	size;

	size = list_size(*a);
	pos = find_min_pos(*a);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < size)
			rra(a);
	}
	pb(a, b);
}
