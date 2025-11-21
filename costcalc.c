/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costcalc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimplegurajani <dimplegurajani@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 01:45:49 by dimpleguraj       #+#    #+#             */
/*   Updated: 2025/11/20 15:11:58 by dimpleguraj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rotation_cost(int index, int size)
{
    if (index <= size / 2)
        return (index);
    return (index - size);
}
int total_cost(int cost_a, int cost_b)
{
    if (cost_a > 0 && cost_b > 0)
        {
            if (cost_a > cost_b)
                return (cost_a);
            else
                return (cost_b);
        }
    if (cost_a < 0 && cost_b < 0)
        {
            if (cost_a < cost_b)
                return (-cost_a);
            else
                return (-cost_b);
        }
    if (cost_a < 0)
        cost_a = -cost_a;
    if (cost_b < 0)
        cost_b = -cost_b;
    return (cost_a + cost_b);
}

t_node  *find_b_to_push(t_node *a, t_node *b, t_cost *best)
{
    t_node  *temp;
    t_node  *best_node;
    t_cost  c;
    int     i;

    temp = b;
    best_node = NULL;
    i = 0;
    best->total = INT_MAX;
    while (temp)
    {
        c.target_a = find_insert_index(a, temp->index);
        c.cost_a = rotation_cost(c.target_a, list_size(a));
        c.cost_b = rotation_cost(i, list_size(b));
        c.total = total_cost(c.cost_a, c.cost_b);
        if (c.total < best->total)
        {
            *best = c;
            best_node = temp;
        }
        temp = temp->next;
        i++;
    }
    return (best_node);
}

