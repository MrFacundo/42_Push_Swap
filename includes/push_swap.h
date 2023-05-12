/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:17:42 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/12 15:27:23 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdarg.h>
#include <limits.h> // LONG_MAX
# include <errno.h>	// errno


// error messages
# define BAD_ARGS "Bad args m8"
# define MALLOC_ERROR "Malloc error m8"
# define UNIQUE_VALUES "Values must be unique m8"
# define NOT_INT "Arg is not an int m8"
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
void	print_node(t_stack_node *stack);

/* checks.c */
int		value_is_unique(t_stack_node *stack, int value);
void	handle_error(t_stack_node **stack, char *message);
int		is_int(char *str);

/* init_nodes.c */
void	set_position(t_stack_node *node);
void	set_target_node(t_stack_node *a, t_stack_node *b);
void 	set_push_cost(t_stack_node *a, t_stack_node *b);
void	set_lowest_cost_node(t_stack_node *b);
void	init_nodes(t_stack_node *a, t_stack_node *b);

/* init_stack.c */
void	stack_init(t_stack_node **stack, char **argv, int argc);

/* main.c */
int		main();

/* moves.c */
void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *node_to_move, char *instruction);
void	rotate_one(t_stack_node **stack, t_stack_node *node, char stack_name);

/* push.c */
void	pa(t_stack_node **a, t_stack_node **b);

/* rotate.c */
void	rotate_stack(t_stack_node **stack, char *instruction);
void	rotate_stacks(t_stack_node **a, t_stack_node **b, char *instruction);



/* stack_utils.c */
t_stack_node	*get_last_node(t_stack_node *head);
t_stack_node 	*get_highest_value_node(t_stack_node *stack);
t_stack_node	*get_lowest_value_node(t_stack_node *node);
t_stack_node	*get_lowest_cost_node(t_stack_node *node);
int				stack_size(t_stack_node *stack);

/* swap.c */

void	sa(t_stack_node **a);
void	sb(t_stack_node **b);

#endif
