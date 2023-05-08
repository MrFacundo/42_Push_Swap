#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	print_node(t_stack_node *stack)
{
	printf("Node address\t value\t prev\t prev address\t next\t next address\n");
	while (stack)
	{
		printf(
			"%p\t %d\t %d\t %p\t %d\t %p\n",
			stack,
			stack->value,
			stack->prev ? stack->prev->value : 0,
			stack->prev ? stack->prev : 0,
			stack->next ? stack->next->value : 0,
			stack->next ? stack->next : 0
			);
		stack = stack->next;
	}
	printf("*********************************\n");
}