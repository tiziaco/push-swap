/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:30:40 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/25 19:06:36 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	move_to_b(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*a;
	t_node	*b;

	a = stack_a->front;

	while (!a->is_cheapest)
		a = a->next;
	while (a != stack_a->front)
	{
		if (a->above_avg)
			rra(stack_a);
		else
			ra(stack_a);
	}
	b = a->target;
	while (b != stack_b->front)
	{
		if (b->above_avg)
			rrb(stack_b);
		else
			rb(stack_b);
	}
	pb(stack_a, stack_b);
}

void	long_sort(t_deque *stack_a, t_deque *stack_b)
{
	int len_a;
	int len_b;

	len_a = lst_len(stack_a);
	len_b = 0;
	while (len_b < 2 && len_a > 3)
	{
		pb(stack_a, stack_b);
		len_a--;
		len_b++;
	}
	while (len_a > 3)
	{
		refresh_node_a(stack_a, stack_b);
		move_to_b(stack_a, stack_b);
		len_a--;
	}
	len_b = lst_len(stack_b);
	simple_sort(stack_a);

	ft_printf("After orfdering B: \n");
	display_deque(stack_a);
	display_deque(stack_b);
	
	refresh_node_b(stack_a, stack_b);
	/* while (len_b == 0)
	{
		refresh_node_b(stack_a, stack_b);
		move_to_a(stack_a, stack_b);
		len_b--;
	} */
	display_deque(stack_a);
	display_deque(stack_b);
}
