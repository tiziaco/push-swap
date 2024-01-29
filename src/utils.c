/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:48:59 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/29 11:54:22 by tiacovel         ###   ########.fr       */
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
	free(data);
}

int	is_num(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0' || str[i] == ' ')
		return (0);
	if ((str[i] == '+' || str[i] == '-') && ft_isdigit((str[i + 1])))
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	sign;
	long	result;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			return (result *= sign);
		i++;
	}
	return (result *= sign);
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
