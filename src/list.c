/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:55:30 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/25 12:47:53 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"
#include <stdio.h>

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->nbr = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	init_deque(t_deque *deque)
{
	deque->front = NULL;
	deque->rear = NULL;
}

int	is_empty(t_deque *deque)
{
	return (deque->front == NULL);
}

// Function to check if the deque has only one element
int	has_only_one_elem(t_deque *deque)
{
	return ((deque->front == deque->rear)
		|| (deque->front != NULL && deque->front->next == NULL));
}

void	insert_front(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (is_empty(deque))
	{
		deque->front = new_node;
		deque->rear = new_node;
	}
	else
	{
		new_node->next = deque->front;
		deque->front->prev = new_node;
		deque->front = new_node;
	}
}

void	insert_rear(t_deque *deque, int data)
{
	t_node	*new_node;

	new_node = create_node(data);
	if (is_empty(deque))
	{
		deque->front = new_node;
		deque->rear = new_node;
	}
	else
	{
		new_node->prev = deque->rear;
		deque->rear->next = new_node;
		deque->rear = new_node;
	}
}

void	delete_front(t_deque *deque)
{
	t_node	*temp;

	if (is_empty(deque))
	{
		printf("Deque is empty. Cannot delete from the front.\n");
		return;
	}
	temp = deque->front;
	deque->front = temp->next;
	if (deque->front == NULL)
		deque->rear = NULL;
	else
		deque->front->prev = NULL;
	free(temp);
}

void	delete_rear(t_deque *deque)
{
	t_node	*temp;

	if (is_empty(deque))
	{
		printf("Deque is empty. Cannot delete from the rear.\n");
		return;
	}
	temp = deque->rear;
	deque->rear = temp->prev;
	if (deque->rear == NULL)
		deque->front = NULL;
	else
		deque->rear->next = NULL;
	free(temp);
}

void	display_deque(t_deque *deque)
{
	t_node	*current;

	if (is_empty(deque))
	{
		printf("Deque is empty.\n");
		return;
	}
	current = deque->front;
	while (current != NULL)
	{
		printf("%d ", current->nbr);
		current = current->next;
	}
	printf("\n");
}

void	free_deque(t_deque *deque)
{
	while (!is_empty(deque))
		delete_front(deque);
}

/* int main() {
	t_deque myDeque;

	init_deque(&myDeque);

	insert_front(&myDeque, 10);
	insert_front(&myDeque, 20);
	insert_rear(&myDeque, 30);
	insert_rear(&myDeque, 40);

	printf("Deque elements: \n");
	display_deque(&myDeque);

	delete_front(&myDeque);
	delete_rear(&myDeque);

	printf("Deque elements after popping: \n");
	display_deque(&myDeque);

	free_deque(&myDeque);

	return (0);
} */
