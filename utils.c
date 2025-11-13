/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 12:15:57 by digulraj          #+#    #+#             */
/*   Updated: 2025/10/23 14:38:38 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **splits)
{
	int	i;

	if (!splits)
		return ;
	i = 0;
	while (splits[i])
		free(splits[i++]);
	free(splits);
}

long	ft_atol(const char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

t_node	*ft_lstnew(int value)
{
	t_node	*elem;

	elem = malloc(sizeof(t_node));
	if (!elem)
		return (NULL);
	elem->value = value;
	elem->next = NULL;
	elem->prev = NULL;
	return (elem);
}

void	ft_lstadd_back(t_node **head, t_node *new_node)
{
	t_node	*temp;

	if (!head || ! new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

void	free_list(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
