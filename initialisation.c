/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:36:14 by digulraj          #+#    #+#             */
/*   Updated: 2025/10/23 14:31:55 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_node *head, int value)
{
	while (head)
	{
		if (head->value == value)
			return (1);
		head = head->next;
	}
	return (0);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_int(char *str, int *output)
{
	int		i;
	long	n;

	i = 0;
	if (!str || !str[i])
		return (0);
	if ((str[i] == '+' || str[i] == '-') && !(is_digit(str[i + 1])))
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	n = ft_atol(str);
	if (n > INT_MAX || n < INT_MIN)
		return (0);
	*output = (int)n;
	return (1);
}

int	create_list(char **splits, t_node **head)
{
	int		i;
	int		value;
	t_node	*elem;

	i = 0;
	while (splits[i])
	{
		if (!is_int(splits[i], &value) || has_duplicate(*head, value))
		{
			write(1, "Error\n", 6);
			return (free_array(splits), 0);
		}
		elem = ft_lstnew(value);
		if (!elem)
		{
			write(1, "Error\n", 6);
			return (free_array(splits), 0);
		}
		ft_lstadd_back(head, elem);
		i++;
	}
	free_array(splits);
	return (1);
}

t_node	*stack_init(int argc, char **argv)
{
	t_node	*head;
	char	**splits;
	int		i;

	head = NULL;
	i = 1;
	while (i < argc)
	{
		splits = ft_split(argv[i], ' ');
		if ((!splits) || (!create_list(splits, &head)))
			return (free_list(head), NULL);
		i++;
	}
	return (head);
}
