/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 16:55:33 by digulraj          #+#    #+#             */
/*   Updated: 2025/10/31 18:12:41 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	void	rotate(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (!head || !*head || !*head->next)
		return ;
	first = *head;
	*head = first->next;
	*head->prev = NULL;
	last = *head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_node	**a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node	**b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

