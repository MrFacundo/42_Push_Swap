#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	main()
{
	// va_list args;

	// va_start(args, str);

	t_list *list = ft_lstnew(1);

	ft_lstiter(list, printf("%d", list->content));
	return (0);
}