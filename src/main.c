/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:49:52 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/22 14:42:41 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	initilise_stack_str(char *str)
{
	char	**buffer;

	buffer = ft_split(str, ' ');
	while (*buffer != 0)
	{
		ft_printf("%s\n", *buffer);
		buffer++;
	}
}

void	initilise_stack_args(char **str)
{
	int	i;

	i = 1;
	while (str[i] != 0)
	{
		ft_printf("OK: %s\n", str[i]);
		i++;
	}
}

/* t_deque	*init_stack(char **str)
{
	
} */

int	main(int argc, char **argv)
{
	/* t_deque	*stack_a;
	t_deque	*stack_b; */

	if (argc <= 1)
	{
		ft_printf("ERROR: please define at least 1 argument!");
		return (EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		initilise_stack_str(argv[1]);
	}
	else
		initilise_stack_args(argv);
	return (0);
}
