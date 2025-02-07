/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:58:06 by ybenchel          #+#    #+#             */
/*   Updated: 2025/02/03 11:19:59 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	indexing(t_list **a)
{
	t_list	*tmp;
	t_list	*top;

	tmp = *a;
	if (!tmp->next)
		return ;
	while (tmp)
	{
		top = *a;
		while (top)
		{
			if (tmp->value > top->value)
				tmp->index++;
			top = top->next;
		}
		tmp = tmp->next;
	}
}

int	ft_is_sorted(t_list *head)
{
	t_list	*current;

	if (!head)
		return (0);
	current = head;
	while (current->next != NULL)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_max(t_list *head)
{
	int		result;
	t_list	*current;

	result = head->value;
	current = head;
	while (current != NULL)
	{
		if (current->value > result)
			result = current->value;
		current = current->next;
	}
	return (result);
}

int	max_index(t_list *stack)
{
	int	highest;

	highest = stack->index;
	while (stack)
	{
		if (stack->index > highest)
			highest = stack->index;
		stack = stack->next;
	}
	return (highest);
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
