/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:38:28 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/18 16:18:06 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	sel_sort(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
				swap(&array[i], &array[j]);
			j++;
		}
		i++;
	}
}

int	get_median(t_node *head, int size)
{
	int			*array;
	int			i;
	int			median;
	t_node		*temp;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (0);
	temp = head;
	i = 0;
	while (temp)
	{
		array[i++] = temp->value;
		temp = temp->next;
	}
	sel_sort(array, size);
	median = array[size / 2];
	free(array);
	return (median);
}
