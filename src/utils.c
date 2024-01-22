/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:48:59 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/22 19:22:00 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	free_split(char **data)
{
	int	i;

	if (data == NULL)
		return ;
	i = 0;
	while (data[i] != NULL)
	{
		free(data[i]);
		i++;
	}
	//free(data);
}

int	is_num(const char* str)
{
	if (str == NULL || *str == '\0')
		return (0);
	if (*str == '+' || *str == '-')
		++str;
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		++str;
	}
	return (1);
}

int	has_duplicates(char **buffer)
{
	int	i;
	int	j;

	i = 0;
	while (buffer[i] != NULL)
	{
		j = i + 1;
		while (buffer[j] != NULL)
		{
			if (ft_strcmp(buffer[i], buffer[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0); // Returns 0 if duplicates are not found
}

/* #include <stdio.h>

int	main(void)
{
	char *str = "+25.";

	if (!is_num(str))
		printf("%s is NOT a number", str);
	else
		printf("%s is a number.", str);
	return (0);
} */

/* #include <stdio.h>
int main()
{
	char	*string = "8.1 orange banana 8.2 grape";
	char	**buffer;

	buffer = ft_split(string, ' ');

	if (has_duplicates(buffer) == 1) {
		printf("Duplicate strings found.\n");
	} else {
		printf("No duplicates found.\n");
	}
	//printf("TEST: %d\n", ft_strcmp("apple", "app"));

	return 0;
} */
