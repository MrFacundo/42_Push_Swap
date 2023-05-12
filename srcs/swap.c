/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:18:24 by facundo           #+#    #+#             */
/*   Updated: 2023/05/12 13:54:28 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !head)
		return ;
    // Update the head pointer to point to the second node in the list
	*head = (*head)->next;
    // Update the previous and next pointers of the former head node
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
    // Update the prev pointer of the last (3rd) node 
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
    // Update the new head node 
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_putstr_fd("sb\n", 1);
}