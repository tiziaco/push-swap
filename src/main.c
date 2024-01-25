/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:49:52 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/24 12:01:58 by tiacovel         ###   ########.fr       */
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
	init_vars(&stack_a, &stack_b);
	init_buffer(&buffer, argc, argv);
	init_stack(stack_a, stack_b, buffer);
	return (0);
} */

void init_argc_argv(int *argc, char ***argv)
{
	*argc = 2;
	*argv = (char **)malloc(*argc * sizeof(char *));
	if (argv == NULL) {
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	// Allocate memory for a single character and set it to a random char
	(*argv)[0] = ft_strdup("aaa");
	if ((*argv)[0] == NULL) {
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	// Allocate memory for a string "10 20 30 40"
	(*argv)[1] = ft_strdup("10 20 30 40");
	if ((*argv)[1] == NULL) {
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
}

void init_argc_argv_2(int *argc, char ***argv)
{
	int j;
	*argc = 5;
	char *tempValues[] = {"10", "20", "30", "40"};

	*argv = (char **)malloc(*argc * sizeof(char *));
	if (*argv == NULL) {
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	// Allocate memory for a single character and set it to a random char
	(*argv)[0] = ft_strdup("aaa");
	if ((*argv)[0] == NULL) {
		ft_printf("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	// Initialize other pointers to NULL
    for (j = 1; j < *argc; j++) {
        (*argv)[j] = NULL;
    }

	// Allocate memory for strings and copy values
	j = 1;
	for (int i = 0; i < *argc - 1; i++) {
		(*argv)[j] = ft_strdup(tempValues[i]);
		if ((*argv)[j] == NULL) {
			ft_printf("Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

int	main(void)
{
	char	**buffer;
	int		argc;
	char	**argv;
	t_deque	*stack_a;
	t_deque	*stack_b;

	init_argc_argv_2(&argc, &argv);

	buffer = NULL;
	if (argc <= 1)
		return (EXIT_SUCCESS);
	init_vars(&stack_a, &stack_b);
	init_buffer(&buffer, argc, argv);
	init_stack(stack_a, stack_b, buffer);

	// Free the allocated memory
	free_split(buffer);
	int i = 0;
	while (argv[i] != NULL)
	{
		//char *tmp = argv[i];
		free(argv[i]);
		i++;
	}
	free(argv);

	return (0);
}