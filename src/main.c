/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:49:52 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/25 16:09:47 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	init_vars(t_deque **stack_a, t_deque **stack_b)
{
	*stack_a = (t_deque *)malloc(sizeof(t_deque));
	*stack_b = (t_deque *)malloc(sizeof(t_deque));
    if (*stack_a == NULL || *stack_b == NULL)
	{
        ft_printf("Error\n");
        exit(EXIT_FAILURE);
    }
}

void	exit_program(int code, t_deque *stack_a, t_deque *stack_b)
{
	free_deque(stack_a);
	free_deque(stack_b);
	free(stack_a);
	free(stack_b);
	exit(code);
}

/* int	main(int argc, char **argv)
{
	char	**buffer;
	t_deque	*stack_a;
	t_deque	*stack_b;

	if (argc <= 1)
		return (EXIT_SUCCESS);
	buffer = NULL;
	init_buffer(&buffer, argc, argv);
	init_vars(&stack_a, &stack_b);
	init_stack(stack_a, stack_b, buffer);
	free_split(buffer);
	exit_program(EXIT_SUCCESS, stack_a, stack_b);
	return (0);
} */


int	main(void)
{
	char	**buffer;
	t_deque	*stack_a;
	t_deque	*stack_b;

	/* int		argc = 4;
	char	*argv[5] = {argv[0] = "aaa\0", argv[1] = "30", argv[2] = "40", argv[3] = "1000", argv[4] = NULL}; */
	int		argc = 2;
	char	*argv[3] = {argv[0] = "aaa\0", argv[1] = "10 40 30 -45 80 54", argv[2] = NULL};

	if (argc <= 1)
		return (EXIT_SUCCESS);
	buffer = NULL;
	init_buffer(&buffer, argc, argv);
	init_vars(&stack_a, &stack_b);
	init_stack(stack_a, stack_b, buffer);
	free_split(buffer);
	sort_stack(stack_a, stack_b);
	display_deque(stack_a);
	exit_program(EXIT_SUCCESS, stack_a, stack_b);

	return (0);
}
