/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:53:18 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/31 15:08:14 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **a, int write_flag)
{
	int	tmp;
	int	index;

	if (!(a) || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)->value;
	index = (*a)->index;
	(*a)->value = (*a)->next->value;
	(*a)->index = (*a)->next->index;
	(*a)->next->value = tmp;
	(*a)->next->index = index;
	if (write_flag)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int write_flag)
{
	int	tmp;
	int	index;

	if (!(b) || !(*b) || !((*b)->next))
		return ;
	tmp = (*b)->value;
	index = (*b)->index;
	(*b)->value = (*b)->next->value;
	(*b)->index = (*b)->next->index;
	(*b)->next->value = tmp;
	(*b)->next->index = index;
	if (write_flag)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b, int write_flag)
{
	sa(a, 0);
	sb(b, 0);
	if (write_flag)
		write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b, int write_flag)
{
	t_list	*first_b;

	if (!b || !*b)
		return ;
	first_b = *b;
	*b = first_b->next;
	first_b->next = *a;
	*a = first_b;
	if (write_flag)
		write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b, int write_flag)
{
	t_list	*first_a;

	if (!a || !*a)
		return ;
	first_a = *a;
	*a = first_a->next;
	first_a->next = *b;
	*b = first_a;
	if (write_flag)
		write(1, "pb\n", 3);
}
