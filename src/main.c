/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:49:52 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/22 19:34:43 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	init_buff_args(char ***buffer, int argc, char **argv)
{
	int	i;
	int	j;

	*buffer = (char **)malloc((argc+1) * sizeof(char *));
	if (*buffer == NULL)
	{
        ft_printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
	i = 1;
	j = 0;
	while (argv[i] != 0)
	{
		//char *tmp = argv[i];
		(*buffer)[j] = ft_strdup(argv[i]);
		i++;
		j++;
	}
	(*buffer)[j] = NULL;
}

void	init_buffer(char ***buffer, int argc, char **argv)
{
	int	i;

	if (argc == 2)
		*buffer = ft_split(argv[1], ' ');
	else
		init_buff_args(buffer, argc, argv);
	i = 0;
	while (buffer[i] != NULL)
	{
		if (!is_num(buffer[i]))
		{
			free_split(buffer);
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (has_duplicates(buffer) == 1)
	{
		free_split(buffer);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}

/* t_deque	*init_stack(char **str)
{
	
} */

void	print_buffer(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
		ft_printf("%s ", data[i]);
		i++;
	}
	free(data);
}

/* int	main(int argc, char **argv)
{
	char	**buffer;

	buffer = NULL;
	if (argc <= 1)
		return (EXIT_SUCCESS);
	init_buffer(buffer, argc, argv);
	//init_stack(buffer);
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

	init_argc_argv_2(&argc, &argv);

	buffer = NULL;
	if (argc <= 1)
		return (EXIT_SUCCESS);
	init_buffer(&buffer, argc, argv);
	print_buffer(buffer);
	//init_stack(buffer);

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