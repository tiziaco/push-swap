/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:30:40 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/25 12:17:02 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	update_index(t_node *stack);

void	find_target(t_node *stack_a, t_node *stack_b);

void    calculate_cost(t_node *stack_a, t_node *stack_b);

void    long_sort(t_deque *stack_a, t_deque *stack_b);