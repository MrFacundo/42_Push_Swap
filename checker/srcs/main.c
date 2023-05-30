/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facundo <facundo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:52:10 by facundo           #+#    #+#             */
/*   Updated: 2023/05/30 15:43:30 by facundo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

void	process_instructions(t_stack_node **a, t_stack_node **b)
{
	t_list	*instructions_list;
	t_list	*temp;

	instructions_list = ft_lstnew(ft_get_next_line(STDIN_FILENO));
	temp = instructions_list;
	while (temp->content)
	{
		if (process_instruction(temp->content, a, b))
		{
			ft_putstr_fd("Instructions error mf\n", STDERR_FILENO);
			free_stack(a);
			free_stack(b);
			ft_lstclear(&instructions_list, free);
			exit(1);
		}
		temp->next = ft_lstnew(ft_get_next_line(STDIN_FILENO));
		temp = temp->next;
	}
	ft_lstclear(&instructions_list, free);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	if (argc == 1)
		return (0);
	a = 0;
	b = 0;
	stack_init(&a, ++argv, --argc);
	process_instructions(&a, &b);
	if (stack_is_sorted(a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
