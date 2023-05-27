/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftroiter <ftroiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:48:33 by facundo           #+#    #+#             */
/*   Updated: 2023/05/27 18:50:57 by ftroiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

int	main(int argc, char **argv)
{
	char			*str;
	int				i;
	t_stack_node	*a;
	t_stack_node	*b;
	t_list			*instructions_list;
	t_list			*temp;

	if (argc == 1)
		return (0);
	a = 0;
	b = 0;
	stack_init(&a, ++argv, --argc);
	str = ft_get_next_line(STDIN_FILENO);
	instructions_list = ft_lstnew(str);
	temp = instructions_list;
	while (temp)
	{
		if (process_instruction(temp->content, &a, &b))
		{
			ft_putstr_fd("Instructions error\n", STDERR_FILENO);
			free_lists(&a, &b, &instructions_list);
			exit(1);
		}
		str = ft_get_next_line(STDIN_FILENO);

		if (str)
			temp->next = ft_lstnew(str);
		temp = temp->next;
	}
	free(str);
	if (stack_is_sorted(a))
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
	free_lists(&a, &b, &instructions_list);
	return (0);
}
