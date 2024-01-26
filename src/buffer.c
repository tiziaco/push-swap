/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:46:48 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/26 13:41:31 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	print_buffer(char **data)
{
	int	i;

	i = 0;
	while (data[i] != NULL)
	{
		ft_printf("%s ", data[i]);
		i++;
	}
	ft_printf("\n");
}

static void	init_buff_args(char ***buffer, int argc, char **argv)
{
	int	i;
	int	j;

	*buffer = (char **)malloc((argc + 1) * sizeof(char *));
	if (*buffer == NULL)
	{
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
	i = 1;
	j = 0;
	while (argv[i] != 0)
	{
		(*buffer)[j] = ft_strdup(argv[i]);
		i++;
		j++;
	}
	(*buffer)[j] = NULL;
}

static int	check_buffer(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		if (!is_num(buffer[i]))
			return (1);
		i++;
	}
	if (has_duplicates(buffer) == 1)
		return (1);
	return (0);
}

void	init_buffer(char ***buffer, int argc, char **argv)
{
	if (argc == 2)
		*buffer = ft_split(argv[1], ' ');
	else
		init_buff_args(buffer, argc, argv);
	if (check_buffer(*buffer) == 1)
	{
		free_split(*buffer);
		ft_printf("Error\n");
		exit(EXIT_FAILURE);
	}
}
