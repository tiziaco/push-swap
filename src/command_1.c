/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:43:22 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/26 13:42:17 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sa(t_deque *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (stack_a->front != NULL && stack_a->front->next != NULL)
	{
		first = stack_a->front;
		second = first->next;
		first->next = second->next;
		second->next = first;
		first->prev = second;
		if (first->next != NULL)
			first->next->prev = first;
		second->prev = NULL;
		if (stack_a->front == first)
			stack_a->front = second;
		if (stack_a->rear == second)
			stack_a->rear = first;
	}
	ft_printf("sa\n");
}

void	sb(t_deque *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (stack_b->front != NULL && stack_b->front->next != NULL)
	{
		first = stack_b->front;
		second = first->next;
		first->next = second->next;
		second->next = first;
		first->prev = second;
		if (first->next != NULL)
			first->next->prev = first;
		second->prev = NULL;
		if (stack_b->front == first)
			stack_b->front = second;
		if (stack_b->rear == second)
			stack_b->rear = first;
	}
	ft_printf("sb\n");
}

void	ss(t_deque *stack_a, t_deque *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*top_b;

	if (stack_b->front != NULL)
	{
		top_b = stack_b->front;
		stack_b->front = top_b->next;
		if (stack_b->front != NULL)
			stack_b->front->prev = NULL;
		top_b->next = stack_a->front;
		top_b->prev = NULL;
		if (stack_a->front != NULL)
			stack_a->front->prev = top_b;
		stack_a->front = top_b;
		if (stack_a->rear == NULL)
			stack_a->rear = top_b;
	}
	ft_printf("pa\n");
}

void	pb(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*top_a;

	if (stack_a->front != NULL)
	{
		top_a = stack_a->front;
		stack_a->front = top_a->next;
		if (stack_a->front != NULL)
			stack_a->front->prev = NULL;
		top_a->next = stack_b->front;
		top_a->prev = NULL;
		if (stack_b->front != NULL)
			stack_b->front->prev = top_a;
		stack_b->front = top_a;
		if (stack_b->rear == NULL)
			stack_b->rear = top_a;
	}
	ft_printf("pb\n");
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

	insert_rear(&stack_b, 150);
	insert_rear(&stack_b, 140);

	ft_printf("Deque elements: \n");
	display_deque(&stack_a);

	sa(&stack_a);
	display_deque(&stack_a);
	sb(&stack_b);
	display_deque(&stack_b);
	ss(&stack_a, &stack_b);
	display_deque(&stack_a);
	pa(&stack_a, &stack_b);
	display_deque(&stack_a);
	display_deque(&stack_b);
	pb(&stack_a, &stack_b);
	display_deque(&stack_a);
	display_deque(&stack_b);

	free_deque(&stack_a);

	return (0);
} */
