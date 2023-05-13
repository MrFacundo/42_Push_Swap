/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:49:48 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/13 14:54:22 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void push(t_stack_node **src, t_stack_node **dst)
{
	t_stack_node	*node_to_push;

	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = 0;
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = 0;
	}
	else
	{
		node_to_push->next = *dst;
		(*dst)->prev = node_to_push;
		*dst = node_to_push;
	}
}

void	push_direction(t_stack_node **a, t_stack_node **b, char *instruction)
{
	if (!ft_strncmp("pa", instruction, 3))
		push(b, a);
	else if (!ft_strncmp("pb", instruction, 3))
		push(a, b);
	ft_putstr_fd(instruction, 1);
	ft_putchar_fd('\n', 1);
}
