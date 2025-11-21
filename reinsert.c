/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reinsert.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 13:56:17 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/21 14:04:09 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	find_min_max(t_node *a, int *mindex, int *maxdex)
{
	t_node	*temp;

	temp = a;
	*mindex = INT_MAX;
	*maxdex = INT_MIN;
	while (temp)
	{
		if (temp->index < *mindex)
			*mindex = temp->index;
		if (temp->index > *maxdex)
			*maxdex = temp->index;
		temp = temp->next;
	}
}

static int	find_wrap_pos(t_node *a)
{
	t_node	*temp;
	int		pos;
	int		minpos;
	int		mindex;

	temp = a;
	mindex = temp->index;
	pos = 0;
	minpos = 0;
	while (temp)
	{
		if (temp->index < mindex)
		{
			mindex = temp->index;
			minpos = pos;
		}
		temp = temp->next;
		pos++;
	}
	return (minpos);
}

int	find_insert_index(t_node *a, int b_index)
{
	t_node	*temp;
	int		pos;
	int		mindex;
	int		maxdex;

	temp = a;
	pos = 0;
	find_min_max(a, &mindex, &maxdex);
	if (b_index < mindex || b_index > maxdex)
		return (find_wrap_pos(a));
	while (temp)
	{
		if (temp->index > b_index)
			return (pos);
		temp = temp->next;
		pos++;
	}
	return (find_wrap_pos(a));
}
