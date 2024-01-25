/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:33:14 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/25 19:05:25 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	find_target_in_a(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*a;
	t_node	*b;
	long	best_target;

	a = stack_a->front;
	b = stack_b->front;
	best_target = LONG_MAX;
	b->target = NULL;
	while (b != NULL)
	{
		while (a != NULL)
		{
			if (a->nbr > b->nbr && a->nbr < best_target)
			{
				b->target = a;
				best_target = a->nbr;
			}
			a = a->next;
		}
		if (b->target == NULL)
			b->target = lst_min(stack_b->front);
		a = stack_a->front;
		b = b->next;
		best_target = LONG_MAX;
	}
}

void	refresh_node_b(t_deque *stack_a, t_deque *stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	find_target_in_a(stack_a, stack_b);
	calculate_cost(stack_b, stack_a);
	find_cheapest(stack_b);
}