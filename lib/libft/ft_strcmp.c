/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiacovel <tiacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:52:56 by tiacovel          #+#    #+#             */
/*   Updated: 2024/01/22 14:34:49 by tiacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (s1[i] == s2[i]))
		i++;
	return (s1[i] - s2[i]);
}
/*
int	main(void)
{
	char s1[] = "Hello";
	char s2[] = "Hello world";

	printf("42 function: %d", ft_strcmp(s1, s2));
	printf("\nSTD function: %d", strcmp(s1, s2));
	return (0);
}
*/
