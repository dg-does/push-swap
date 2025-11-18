/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:55:33 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/18 16:11:46 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	revrotate(t_node **head)
{
	t_node	*prev;
	t_node	*last;

	if (!head || !*head || !(*head)->next)
		return ;
	last = *head;
	while (last->next)
		last = last->next;
	prev = last->prev;
	prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	*head = last;
}

void	rra(t_node	**a)
{
	revrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node	**b)
{
	revrotate(b);
	write(1, "rrb\n", 4);
}
