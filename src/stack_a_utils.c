/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:33:14 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/26 13:53:21 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	update_index(t_deque *stack)
{
	int		i;
	int		avg;
	t_node	*node;

	i = 0;
	avg = lst_len(stack) / 2;
	node = stack->front;
	while (node != NULL)
	{
		node->index = i;
		if (i < avg)
			node->above_avg = false;
		else
			node->above_avg = true;
		node = node->next;
		i++;
	}
}

static void	find_target_in_b(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*a;
	t_node	*b;
	long	best_target;

	a = stack_a->front;
	b = stack_b->front;
	best_target = LONG_MIN;
	a->target = NULL;
	while (a != NULL)
	{
		while (b != NULL)
		{
			if (b->nbr < a->nbr && b->nbr > best_target)
			{
				a->target = b;
				best_target = b->nbr;
			}
			b = b->next;
		}
		if (a->target == NULL)
			a->target = lst_max(stack_b->front);
		b = stack_b->front;
		a = a->next;
		best_target = LONG_MIN;
	}
}

void	calculate_cost(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*a;
	int		len_a;
	int		len_b;

	len_a = lst_len(stack_a);
	len_b = lst_len(stack_b);
	a = stack_a->front;
	while (a != NULL)
	{
		a->cost = a->index;
		if (a->above_avg)
			a->cost = (len_a - a->index);
		if (a->target->above_avg)
			a->cost += (len_b - a->target->index);
		else
			a->cost += a->target->index;
		a = a->next;
	}
}

void	find_cheapest(t_deque *stack)
{
	t_node	*node;
	t_node	*cheapest;
	int		min;

	min = INT_MAX;
	node = stack->front;
	while (node != NULL)
	{
		if (node->cost < min)
		{
			min = node->cost;
			cheapest = node;
		}
		node = node->next;
	}
	cheapest->is_cheapest = true;
}

void	refresh_node_a(t_deque *stack_a, t_deque *stack_b)
{
	update_index(stack_a);
	update_index(stack_b);
	find_target_in_b(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	find_cheapest(stack_a);
}
