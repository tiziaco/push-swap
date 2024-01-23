/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:43:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/23 13:21:25 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void ra(t_deque *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!is_empty(stack_a) && stack_a->front != stack_a->rear)
	{
		first = stack_a->front;
		second = first->next;

		// Remove the first element from stack_a
		stack_a->front = second;
		second->prev = NULL;

		// Add the first element to the rear of stack_a
		first->next = NULL;
		first->prev = stack_a->rear;
		stack_a->rear->next = first;
		stack_a->rear = first;
	}
	ft_printf("ra\n");
}

void rb(t_deque *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!is_empty(stack_b) && stack_b->front != stack_b->rear) {
		first = stack_b->front;
		second = first->next;

		// Remove the first element from stack_b
		stack_b->front = second;
		second->prev = NULL;

		// Add the first element to the rear of stack_b
		first->next = NULL;
		first->prev = stack_b->rear;
		stack_b->rear->next = first;
		stack_b->rear = first;
	}
	ft_printf("rb\n");
}

void rr(t_deque *stack_a, t_deque *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

int main(void)
{
	t_deque	stack_a;
	t_deque	stack_b;

	init_deque(&stack_a);
	init_deque(&stack_b);

	insert_front(&stack_a, 10);
	insert_front(&stack_a, 20);
	insert_rear(&stack_a, 30);
	insert_rear(&stack_a, 40);

	insert_front(&stack_b, 110);
	insert_front(&stack_b, 120);
	insert_rear(&stack_b, 130);
	insert_rear(&stack_b, 140);

	ft_printf("Deque elements: \n");
	display_deque(&stack_a);
	display_deque(&stack_b);

	ra(&stack_a);
	display_deque(&stack_a);
	rb(&stack_b);
	display_deque(&stack_b);
	rr(&stack_a, &stack_b);
	display_deque(&stack_a);
	display_deque(&stack_b);

	free_deque(&stack_a);
	free_deque(&stack_b);

	return (0);
}
