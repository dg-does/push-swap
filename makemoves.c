/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemoves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 02:16:03 by dimpleguraj       #+#    #+#             */
/*   Updated: 2025/11/21 13:08:37 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    do_combined_rotations(t_node **a, t_node **b, t_cost *c)
{
    while (c->cost_a > 0 && c->cost_b > 0)
    {
        rr(a, b);
        c->cost_a--;
        c->cost_b--;
    }
    while (c->cost_a < 0 && c->cost_b < 0)
    {
        rrr(a, b);
        c->cost_a++;
        c->cost_b++;
    }
}
static void    do_single_rotations(t_node **a, t_node **b, t_cost *c)
{
    while (c->cost_a > 0)
    {
        ra(a);
        c->cost_a--;
    }
    while (c->cost_a < 0)
    {
        rra(a);
        c->cost_a++;
    }
    while (c->cost_b > 0)
    {
        rb(b);
        c->cost_b--;
    }
    while (c->cost_b < 0)
    {
        rrb(b);
        c->cost_b++;
    }
}

static void    make_moves(t_node **a, t_node **b, t_cost *c)
{
    do_combined_rotations(a, b, c);
    do_single_rotations(a, b, c);
    pa(a, b);
}

void    push_back_to_a(t_node **a, t_node **b)
{
    t_cost  best;
    int     mindex;
    int     cost;

    while(*b)
    {
        find_b_to_push(*a, *b, &best);
        make_moves(a, b, &best);
    }
    mindex = find_insert_index(*a, INT_MIN);
    cost = rotation_cost(mindex, list_size(*a));
    while (cost > 0)
    {
        ra(a);
        cost--;
    }
    while (cost < 0)
    {
        rra(a);
        cost++;
    }
}

