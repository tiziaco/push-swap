/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:11:40 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/26 13:54:50 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_stack(t_deque *stack_a, t_deque *stack_b)
{
	if (is_ordered(stack_a) == 1 || has_only_one_elem(stack_a) == 1)
		exit_program(EXIT_SUCCESS, stack_a, stack_b);
	if (lst_len(stack_a) <= 3)
		simple_sort(stack_a);
	else
		long_sort(stack_a, stack_b);
}
