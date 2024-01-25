/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:45:52 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/24 17:27:38 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	int 			cost;
	bool			above_med;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_deque
{
	t_node	*front;
	t_node	*rear;
}	t_deque;

// ** To be deleted ** //
void	display_deque(t_deque *deque);
// ******************* //
void	exit_program(int code, t_deque *stack_a, t_deque *stack_b);

int		is_num(const char* str);
int		has_duplicates(char **buffer);
int		lst_len(t_deque *deque);
t_node	*lst_min(t_node *stack);
t_node	*lst_max(t_node *stack);

void	free_split(char **data);
void	free_deque(t_deque *deque);

void	init_buffer(char ***buffer, int argc, char **argv);
void	init_stack(t_deque *stack_a, t_deque *stack_b, char **buffer);

int		is_empty(t_deque *deque);
void	init_deque(t_deque *deque);
void	insert_front(t_deque *deque, int data);
void	insert_rear(t_deque *deque, int data);
void	delete_front(t_deque *deque);
void	delete_rear(t_deque *deque);

void	sa(t_deque *stack_a);
void	sb(t_deque *stack_b);
void	ss(t_deque *stack_a, t_deque *stack_b);
void	pa(t_deque *stack_a, t_deque *stack_b);
void	pb(t_deque *stack_a, t_deque *stack_b);
void	ra(t_deque *stack_a);
void	rb(t_deque *stack_b);
void	rr(t_deque *stack_a, t_deque *stack_b);
void	rra(t_deque *stack_a);
void	rrb(t_deque *stack_b);
void	rrr(t_deque *stack_a, t_deque *stack_b);

#endif