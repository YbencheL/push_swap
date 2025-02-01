/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 20:53:17 by ybenchel          #+#    #+#             */
/*   Updated: 2025/01/31 15:09:35 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_list **a, int write_flag)
{
	t_list	*first;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (write_flag)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int write_flag)
{
	t_list	*first;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	first->next = NULL;
	last->next = first;
	if (write_flag)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int write_flag)
{
	ra(a, 0);
	rb(b, 0);
	if (write_flag)
		write(1, "rr\n", 3);
}

void	rra(t_list **a, int write_flag)
{
	t_list	*last;
	t_list	*second_last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *a;
	*a = last;
	if (write_flag)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int write_flag)
{
	t_list	*last;
	t_list	*second_last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *b;
	*b = last;
	if (write_flag)
		write(1, "rrb\n", 4);
}
