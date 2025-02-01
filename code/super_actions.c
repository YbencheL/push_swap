/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 11:42:02 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/30 16:57:04 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_distance(t_list **stack, int pos)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*stack);
	while (tmp)
	{
		if (tmp->index == pos)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	find_first_index(t_list *head, int i, int p)
{
	int		index;
	t_list	*current;

	index = 0;
	current = head;
	while (current != NULL)
	{
		if (current->index <= i + p)
			return (index);
		index++;
		current = current->next;
	}
	return (index);
}

void	push_to_b(t_list **s_a, t_list **s_b, int p)
{
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(*s_a);
	while (i < len)
	{
		if ((*s_a)->index <= i)
		{
			pb(s_a, s_b, 1);
			rb(s_b, 1);
			i++;
		}
		else if ((*s_a)->index <= i + p)
		{
			pb(s_a, s_b, 1);
			i++;
		}
		else if (find_first_index(*s_a, i, p) < ft_lstsize(*s_a) / 2)
			ra(s_a, 1);
		else
			rra(s_a, 1);
	}
}

void	rotate_stack_b(t_list **stack_b, int highest_idx,
		int highest_idx_m_1)
{
	if (find_distance(stack_b, highest_idx) > ft_lstsize(*stack_b) / 2)
	{
		while ((*stack_b)->index != highest_idx
			&& (*stack_b)->index != highest_idx_m_1)
			rrb(stack_b, 1);
	}
	else
	{
		while ((*stack_b)->index != highest_idx
			&& (*stack_b)->index != highest_idx_m_1)
			rb(stack_b, 1);
	}
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	int		highest_idx;
	int		highest_idx_m_1;

	while (*stack_b)
	{
		highest_idx = highest_index(*stack_b);
		highest_idx_m_1 = highest_idx - 1;
		if ((*stack_b)->index == highest_idx
			|| (*stack_b)->index == highest_idx_m_1)
			pa(stack_a, stack_b, 1);
		else
			rotate_stack_b(stack_b, highest_idx, highest_idx_m_1);
		if (ft_lstsize(*stack_a) > 1
			&& (*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, 1);
	}
}
