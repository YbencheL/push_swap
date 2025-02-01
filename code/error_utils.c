/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:04:25 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/31 15:09:26 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_numbers(char **numbers)
{
	int	j;

	j = 0;
	while (numbers[j])
	{
		free(numbers[j]);
		j++;
	}
	free(numbers);
}

void	ft_error(char **numbers, t_list **head)
{
	write(2, "Error\n", 6);
	free_numbers(numbers);
	ft_lstclear(head);
	exit(1);
}

void	process_numbers(char **numbers, t_list **stack_a)
{
	int		i;
	long	num;
	t_list	*new;

	i = 0;
	if (numbers[i] == NULL)
		ft_error(numbers, stack_a);
	while (numbers[i])
	{
		if (!is_number(numbers[i]))
			ft_error(numbers, stack_a);
		num = ft_atoi(numbers[i]);
		if (num > INT_MAX || num < INT_MIN)
			ft_error(numbers, stack_a);
		if (is_duplicate(*stack_a, num))
			ft_error(numbers, stack_a);
		new = ft_lstnew(num);
		if (!new)
			ft_error(numbers, stack_a);
		ft_lstadd_back(stack_a, new);
		i++;
	}
	free_numbers(numbers);
}
