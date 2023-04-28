#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	print_int(void *content)
{
	int value = *(int *)content;
 	printf("%d\n", *(int *)content);
}

t_stack_node	*get_last_node(t_stack_node *head)
{
	if (!head)
		return 0;
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(t_stack_node **stack, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_stack_node));
	if (!new_node)
		return ;
	new_node->next = 0;
	new_node->value = nbr;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = 0;
	}
	else
	{
		last_node = get_last_node(stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	stack_init(t_stack_node **stack, char **argv)
{
	int nbr;
	int	i;

	while(argv[i])
	{
		nbr = ft_atoi(argv[i]);
		append_node(stack, nbr);
		i++;
	}
}

int	main()
{
	t_stack_node	*a;
	char	*values[5] = {values[0] = "\0", values[1] = "100", values[2] = "200", values[3] = "50", values[4] = "150"};
	a = 0;
	stack_init(&a, values + 1);
	return (0);
}