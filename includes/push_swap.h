/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:17:42 by ftroiter          #+#    #+#             */
/*   Updated: 2023/04/28 16:36:43 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

/* push_swap.c */
int			main(int argc, char **argv);

#endif
