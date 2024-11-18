/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salabbe <salabbe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:31:13 by salabbe           #+#    #+#             */
/*   Updated: 2024/11/14 11:40:37 by salabbe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		len_s1;
	int		len_s2;
	char	*str;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!str)
		return (NULL);
	while (len_s1 != 0 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (len_s2 != 0 && s2[i])
	{
		str[len_s1 + i] = s2[i];
		i++;
	}
	str[len_s1 + len_s2] = 0;
	free(s1);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char		*tab;
	size_t		i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	tab = malloc(sizeof(char) * (nmemb * size));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		tab[i] = 0;
		i++;
	}
	return ((void *) tab);
}

int	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_isnewline(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
