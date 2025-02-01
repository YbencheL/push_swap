/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:52:48 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/31 11:28:10 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_e_error(t_list **stack_a)
{
	write(2, "Error\n", 6);
	ft_lstclear(stack_a);
	exit(1);
}

static void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	if (!*stack_a)
		return ;
	if (ft_is_sorted(*stack_a))
		return ;
	else if (ft_lstsize(*stack_a) <= 3)
		ft_sort_3(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		ft_sort_5(stack_a, stack_b);
	else
		ft_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;
	char	**numbers;

	stack_a = NULL;
	stack_b = NULL;
	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (!av[i][0])
				ft_e_error(&stack_a);
			numbers = ft_split(av[i], ' ');
			process_numbers(numbers, &stack_a);
			i++;
		}
		sort_stacks(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
	}
	return (0);
}
