/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digulraj <digulraj@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:38:47 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/18 16:09:44 by digulraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int			has_duplicate(t_node *head, int value);
int			is_digit(char c);
int			is_int(char *str, int *output);
int			create_list(char **splits, t_node **head);
t_node		*stack_init(int ac, char **av);

void		free_array(char **splits);
long		ft_atol(const char *str);
t_node		*ft_lstnew(int value);
void		ft_lstadd_back(t_node **head, t_node *new_node);
void		free_list(t_node *head);
char		**ft_split(char const *s, char c);
int			is_sorted(t_node *head);

void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);
void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);
void		rra(t_node	**a);
void		rrb(t_node	**b);
void		rra(t_node	**a);
void		ra(t_node	**a);
void		rb(t_node	**b);
void		rr(t_node **a, t_node **b);

int			list_size(t_node *head);
int			find_min_pos(t_node *head);
int			find_max_pos(t_node *head);
void		push_min_to_b(t_node **a, t_node **b);
void		push_max_to_a(t_node **a, t_node **b);
int			get_median(t_node *head, int size);
void		sort_small(t_node **a, t_node **b);
void		sort_three(t_node **a);

#endif
