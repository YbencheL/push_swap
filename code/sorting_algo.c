/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:01:22 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/31 12:16:10 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_3(t_list **a)
{
	int		max;
	t_list	*lst;

	if (ft_lstsize(*a) == 1)
		return ;
	max = ft_max(*a);
	lst = *a;
	if (lst->value == max)
		ra(a, 1);
	else if (lst->next->value == max)
		rra(a, 1);
	lst = *a;
	if (lst->value > lst->next->value)
		sa(a, 1);
}

void	ft_sort_5(t_list **a, t_list **b)
{
	int	size;
	int	i;

	indexing(a);
	size = ft_lstsize(*a);
	i = 0;
	while (i < 2)
	{
		while ((*a)->index != i)
		{
			if (find_distance(a, i) <= size / 2)
				ra(a, 1);
			else
				rra(a, 1);
		}
		pb(a, b, 1);
		i++;
	}
	ft_sort_3(a);
	while (*b)
		pa(a, b, 1);
}

void	ft_sort(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	indexing(a);
	if (!ft_is_sorted(*a))
	{
		if (len <= 400)
			push_to_b(a, b, 15);
		else
			push_to_b(a, b, 30);
		push_to_a(a, b);
	}
}
