/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimplegurajani <dimplegurajani@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:38:47 by digulraj          #+#    #+#             */
/*   Updated: 2025/11/20 16:43:42 by dimpleguraj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct s_node {
	int				value;
    int             index;
    int             in_lis;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_cost
{
    int target_a;   // index in stack A where the element should be inserted
    int cost_a;     // number of moves to rotate A to bring target_a to top
    int cost_b;     // number of moves to rotate B to bring the element to top
    int total;      // total cost (used to find the best move)
}   t_cost;

void        print_stack(t_node *a);
void		free_list(t_node *head);
int			list_size(t_node *head);
int         find_insert_index(t_node *a, int b_index);
int         *stack_to_array(t_node *a, int size);
int         *build_lis_mask(t_node *head, int size);
t_node      *find_b_to_push(t_node *a, t_node *b, t_cost *best);
int         rotation_cost(int index, int size);
void	    push_min_to_b(t_node **a, t_node **b);
void        push_back_to_a(t_node **a, t_node **b);
void		sort_small(t_node **a, t_node **b);
void		sort_three(t_node **a);

void        assign_index(t_node *head);
void        extract_lis(t_node **a, t_node **b);
void        mark_lis_nodes(t_node *a, int *lis, int lis_len);
int         *compute_lis_indices(t_node *a, int *lis_len);

int			has_duplicate(t_node *head, int value);
int			is_digit(char c);
int			is_int(char *str, int *output);
int			create_list(char **splits, t_node **head);
t_node		*stack_init(int ac, char **av);

void		free_array(char **splits);
long		ft_atol(const char *str);
t_node		*ft_lstnew(int value);
void		ft_lstadd_back(t_node **head, t_node *new_node);
char		**ft_split(char const *s, char c);
int			is_sorted(t_node *head);

void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);
void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);
void		rra(t_node	**a);
void		rrb(t_node	**b);
void		rrr(t_node	**a, t_node **b);
void		ra(t_node	**a);
void		rb(t_node	**b);
void		rr(t_node **a, t_node **b);

#ifndef DEBUG
# define DEBUG 1
#endif

void    debug_stack(const char *msg, t_node *a, t_node *b);
void    debug_mask(const char *msg, int *mask, int size);


#endif
