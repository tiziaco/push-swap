/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:45:52 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/22 15:07:45 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct	s_node
{
	int data;
	struct s_node* next;
	struct s_node* prev;
}	t_node;

typedef struct s_deque
{
	struct s_node	*front;
	struct s_node	*rear;
}	t_deque;

int		is_num(const char* str);
int		has_duplicates(char **buffer);
void	free_split(char **data);

#endif