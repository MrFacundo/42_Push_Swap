/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:50:41 by facundo           #+#    #+#             */
/*   Updated: 2023/05/22 17:25:47 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>

#ifndef CHECKER_H
# define CHECKER_H

#include <stdarg.h>
#include <limits.h> // LONG_MAX
# include <errno.h>	// errno

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
	int					position;
	int					above_median;
	int					push_cost;
	int					has_lowest_cost;
}				t_stack_node;

/* debug.c */
void	print_stack(t_stack_node *stack);

/* checks.c */
int		value_is_unique(t_stack_node *stack, int value);
int		is_int(char *str);
void	free_stack(t_stack_node **stack);

/* init_nodes.c */
void	set_position(t_stack_node *node);
void	set_target_node(t_stack_node *a, t_stack_node *b);
void 	set_push_cost(t_stack_node *a, t_stack_node *b);
void	set_lowest_cost_node(t_stack_node *b);
void	init_nodes(t_stack_node *a, t_stack_node *b);

/* init_stack.c */
void	stack_init(t_stack_node **stack, char **argv, int argc, int *error);

/* main.c */
int		main();

/* moves.c */
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *node_to_move, char *instruction);
void	rotate_one(t_stack_node **stack, t_stack_node *node, char stack_name);

/* push.c */
void	push(t_stack_node **src, t_stack_node **dst);

/* rotate.c */
void	rotate_direction(t_stack_node **stack, int direction);

/* stack_utils.c */
t_stack_node	*get_last_node(t_stack_node *head);
t_stack_node 	*get_highest_value_node(t_stack_node *stack);
t_stack_node	*get_lowest_value_node(t_stack_node *node);
t_stack_node	*get_lowest_cost_node(t_stack_node *node);
int				stack_size(t_stack_node *stack);

/* swap.c */
void	swap(t_stack_node **head);

#endif
