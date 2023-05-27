/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:54:38 by ftroiter          #+#    #+#             */
/*   Updated: 2023/05/27 18:00:25 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

void	handle_error(t_stack_node **stack)
{
	ft_putstr_fd("Args error\n", STDERR_FILENO);
	free_stack(stack);
	exit(1);
}

void	free_lists(t_stack_node **a, t_stack_node **b, t_list **instruction_list)
{
	free_stack(a);
	free_stack(b);
	ft_lstclear(instruction_list, free);
}