/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimplegurajani <dimplegurajani@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:57:56 by dimpleguraj       #+#    #+#             */
/*   Updated: 2025/11/20 17:11:29 by dimpleguraj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *stack_to_array(t_node *a, int size)
{
    int *arr;
    int i;

    arr = malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    i = 0;
    while (i < size && a)
    {
        arr[i] = a->index;
        a = a->next;
        i++;
    }
    return (arr);
}

void    assign_index(t_node *head)
{
    t_node  *i;
    t_node  *j;
    int     rank;

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

void mark_lis_nodes(t_node *a, int *lis, int lis_len)
{
    t_node  *temp;
    int     i;

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

void    extract_lis(t_node **a, t_node **b)
{
    t_node  *temp;
    int     remaining;

    debug_stack("==== Before LIS extraction ====", *a, *b);

    remaining; = list_size(*a);
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
        debug_stack("Step", *a, *b);
    }
    debug_stack("====== After LIS extraction =====", *a, *b);
}

int find_insert_index(t_node *a, int b_index)
{
    t_node  *temp;
    int     pos;
    int     mindex;
    int     minpos;

    pos = 0;
    temp = a;
    mindex = temp->index;
    minpos = 0;

    while (temp)
    {
        if (temp->index < mindex)
        {
            mindex = temp->index;
            minpos = pos;
        }
        if (temp->index > b_index)
            return (pos);
        temp = temp->next;
        pos++;
    }
    return (minpos);
}