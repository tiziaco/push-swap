/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:43:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/25 12:50:02 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	rra(t_deque *stack_a)
{
	t_node	*last;
	t_node	*second_last;

	if (!is_empty(stack_a) && stack_a->front != stack_a->rear)
	{
		last = stack_a->rear;
		second_last = last->prev;

		// Remove the last element from stack_a
		stack_a->rear = second_last;
		second_last->next = NULL;

		// Add the last element to the front of stack_a
		last->prev = NULL;
		last->next = stack_a->front;
		stack_a->front->prev = last;
		stack_a->front = last;
	}
	ft_printf("rra\n");
}

// Function to reverse rotate elements of stack_b
void	rrb(t_deque *stack_b)
{
	t_node	*last;
	t_node	*second_last;

	if (!is_empty(stack_b) && stack_b->front != stack_b->rear)
	{
		last = stack_b->rear;
		second_last = last->prev;

		// Remove the last element from stack_b
		stack_b->rear = second_last;
		second_last->next = NULL;

		// Add the last element to the front of stack_b
		last->prev = NULL;
		last->next = stack_b->front;
		stack_b->front->prev = last;
		stack_b->front = last;
	}
	ft_printf("rrb\n");
}

// Function to perform rra and rrb at the same time
void	rrr(t_deque *stack_a, t_deque *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}

/* int main(void)
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

	rra(&stack_a);
	display_deque(&stack_a);
	rrb(&stack_b);
	display_deque(&stack_b);
	rrr(&stack_a, &stack_b);
	display_deque(&stack_a);
	display_deque(&stack_b);

	free_deque(&stack_a);
	free_deque(&stack_b);

	return (0);
} */
