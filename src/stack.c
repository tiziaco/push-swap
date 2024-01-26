/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:47:43 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/26 13:46:35 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

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
	ft_printf("Stack A:\n");
	display_deque(stack_a);
}
