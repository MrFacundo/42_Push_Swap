/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:17:42 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/08 11:03:45 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdarg.h>
#include <limits.h> // LONG_MAX


typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target_node;
	int					position;
	int					above_median;
	int					push_cost;
}				t_stack_node;

/* push_swap.c */
int			main();
void		init_nodes(t_stack_node *a, t_stack_node *b);

#endif
