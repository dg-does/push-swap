/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:38:28 by digulraj          #+#    #+#             */
/*   Updated: 2025/10/23 16:35:15 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack;
	t_node	*tmp;

	if (argc < 2)
		return (0);
	stack = stack_init(argc, argv);
	if (!stack)
		return (1);
	tmp = stack;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n Stack sorted: %i", is_sorted(stack));
	free_list(stack);
	return (0);
}
/*
int	main(int ac, char **av)
{
	t_node	*stacka;
	t_node	*sta

	stacka = NULL;
	stackb = NULL;

	i = 0;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
stack_init(FILL IN!!);
	if (!is_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
*/


