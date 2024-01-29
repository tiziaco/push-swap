/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:47:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/29 12:22:35 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int	check_nbr(long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

int	has_duplicates(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*node;
	t_node	*next;

	node = stack_a->front;
	while (node != NULL && node->next != NULL)
	{
		next = node->next;
		while (next != NULL)
		{
			if (node->nbr == next->nbr)
			{
				ft_printf("Error\n");
				exit_program(EXIT_FAILURE, stack_a, stack_b);
			}
			next = next->next;
		}
		node = node->next;
	}
	return (0);
}

void	init_stack(t_deque *stack_a, t_deque *stack_b, char **buffer)
{
	int		i;
	long	nbr;

	init_deque(stack_a);
	init_deque(stack_b);
	i = 0;
	while (buffer[i] != NULL)
	{
		nbr = ft_atol(buffer[i]);
		if (check_nbr(nbr) == 0)
		{
			free_split(buffer);
			ft_printf("Error\n");
			exit_program(EXIT_FAILURE, stack_a, stack_b);
		}
		insert_rear(stack_a, (int)nbr);
		i++;
	}
	free_split(buffer);
	has_duplicates(stack_a, stack_b);
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
		return ;
	temp = deque->front;
	deque->front = temp->next;
	if (deque->front == NULL)
		deque->rear = NULL;
	else
		deque->front->prev = NULL;
	free(temp);
}
