/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:11:40 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/25 14:24:34 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	sort_stack(t_deque *stack_a, t_deque *stack_b)
{
	if (lst_len(stack_a) <= 3 )
		simple_sort(stack_a, stack_b);
	else
		ft_printf("To be implemented...");
}