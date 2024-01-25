/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:47 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/25 14:45:35 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	simple_sort(t_deque *stack_a, t_deque *stack_b)
{
	t_node	*first;
	t_node	*max_node;

	first = stack_a->front;
	if (is_ordered(stack_a) == 1 || has_only_one_elem(stack_a) == 1)
		exit_program(EXIT_SUCCESS, stack_a, stack_b);
	max_node = lst_max(first);
	if (max_node == first) //Check if the current node is the biggest
		ra(stack_a); //If so, rotate the top node to the bottom of the stack
	else if ((first)->next == max_node) //Check if the second node is the biggest
		rra(stack_a); //If so, reverse rotate the bottom node, to the top of the stack
	first = stack_a->front;
	if ((first)->nbr > (first)->next->nbr) //Check if the bottom node is the biggest, but the top node is higher than the second node
		sa(stack_a); //If so, simply swap the top and second nodes
}
