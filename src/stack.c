/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:47:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/23 12:13:13 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static int	is_ordered(t_deque *stack_a)
{
	t_node	*current;

	current = stack_a->front;
	while (current != NULL && current->next != NULL)
	{
		if (current->data > current->next->data)
            return 0;
		current = current->next;
	}
}

void	init_stack(t_deque *stack_a, t_deque *stack_b, char **buffer)
{
	int	i;

	init_deque(stack_a);
	init_deque(stack_b);
	i = 0;
	while (buffer[i] != NULL)
	{
		insert_rear(stack_a, ft_atoi(buffer[i]));
		i++;
	}
	if (is_ordered(stack_a) == 0 || has_only_one_elem(stack_a))
	{
		//TODO: free the buffer ans stack memory
		exit(EXIT_SUCCESS);
	}
	ft_printf("Stack A:\n");
	display_deque(stack_a);
}