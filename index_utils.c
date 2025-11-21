/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:57:56 by dimpleguraj       #+#    #+#             */
/*   Updated: 2025/11/21 18:42:47 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *head)
{
	t_node	*i;
	t_node	*j;
	int		rank;

	i = head;
	while (i)
	{
		rank = 0;
		j = head;
		while (j)
		{
			if (j->value < i->value)
				rank++;
			j = j->next;
		}
		i->index = rank;
		i = i->next;
	}
}

void	mark_lis_nodes(t_node *a, int *lis, int lis_len)
{
	t_node	*temp;
	int		i;

	temp = a;
	while (temp)
	{
		temp->in_lis = 0;
		i = 0;
		while (i < lis_len)
		{
			if (temp->index == lis[i])
			{
				temp->in_lis = 1;
				break ;
			}
			i++;
		}
		temp = temp->next;
	}
}

void	extract_lis(t_node **a, t_node **b)
{
	t_node	*temp;
	int		remaining;

	remaining = list_size(*a);
	while (remaining > 0)
	{
		temp = *a;
		if (!temp)
			break ;
		if (temp->in_lis)
			ra(a);
		else
			pb(a, b);
		remaining--;
	}
}

