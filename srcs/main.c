#include "../includes/push_swap.h"
#include "../libft/libft.h"


void	print_int(void *content)
{
	int value = *(int *)content;
	printf("%d\n", *(int *)content);
}

// Take the first element at the top of b and put it at the top of a. 
// Do nothing if b is empty
void	pa(t_list **a, t_list **b)
{

	t_list *b_last;

	b_last = ft_lstlast(b);

	ft_lstadd_back(a, ft_lstnew(b_last->content));

	ft_lstdelone(b_last, free);
}


int	main(int argc, char *argv[])
{
	int i;
	t_list *list = 0;
	int *content;
	i = 1;

	while (i < argc)
	{
		content = malloc(sizeof(int));
		*content = ft_atoi(argv[i]);
		ft_lstadd_back(&list, ft_lstnew(content));
		i++;
	}

	ft_lstiter(list, print_int);
	return (0);
}
