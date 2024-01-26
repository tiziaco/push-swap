/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:02:47 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/26 13:46:08 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	simple_sort(t_deque *stack_a)
{
	t_node	*first;
	t_node	*max_node;

	first = stack_a->front;
	max_node = lst_max(first);
	if (max_node == first)
		ra(stack_a);
	else if ((first)->next == max_node)
		rra(stack_a);
	first = stack_a->front;
	if ((first)->nbr > (first)->next->nbr)
		sa(stack_a);
}
