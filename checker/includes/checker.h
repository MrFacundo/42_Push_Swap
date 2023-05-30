/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:50:41 by facundo           #+#    #+#             */
/*   Updated: 2023/05/30 15:34:21 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdarg.h>
# include <limits.h> // LONG_MAX
# include <errno.h>	// errno
# include "../../libft/libft.h"

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

/* checks.c */
int				value_is_unique(t_stack_node *stack, int value);
int				is_int(char *str);
void			free_stack(t_stack_node **stack);
void			handle_error(t_stack_node **stack);

/* init_nodes.c */
void			set_position(t_stack_node *node);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_push_cost(t_stack_node *a, t_stack_node *b);
void			set_lowest_cost_node(t_stack_node *b);
void			init_nodes(t_stack_node *a, t_stack_node *b);

/* init_stack.c */
void			stack_init(t_stack_node **stack, char **argv, int argc);

/* main.c */
int				main(int argc, char **argv);

/* process.c */
int				process_instruction(char *instruction,
					t_stack_node **a,
					t_stack_node **b);
int				stack_is_sorted(t_stack_node *stack);

/* push.c */
void			push(t_stack_node **src, t_stack_node **dst);

/* rotate.c */
void			rotate_direction(t_stack_node **stack, int direction);

/* stack_utils.c */
t_stack_node	*get_last_node(t_stack_node *head);
t_stack_node	*get_highest_value_node(t_stack_node *stack);
t_stack_node	*get_lowest_value_node(t_stack_node *node);
t_stack_node	*get_lowest_cost_node(t_stack_node *node);
int				stack_size(t_stack_node *stack);

/* swap.c */
void			swap(t_stack_node **head);

#endif
