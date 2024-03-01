/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:11:42 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/01 14:20:06 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

static char	**split_free(char **splits)
{
	size_t	j;

	j = -1;
	while (splits[++j])
		free(splits[j]);
	free(splits);
	return (NULL);
}

static size_t	ft_wordctd(const char *str, char c, char ***splits)
{
	size_t	ctd;
	size_t	i;
	size_t	start;

	ctd = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			ctd++;
		start = i;
		while (str[i] != c && str[i])
			i++;
		if (*splits && ctd > 0 && i != start) 
			(*splits)[ctd - 1] = ft_substr(str, start, i - start);
		if (*splits && ctd && !(*splits)[ctd - 1])
		{
			(*splits) = split_free(*splits);
			return (0);
		}
	}
	return (ctd);
}

char	**ft_split(char const *s, char c)
{
	char	**splits;

	splits = NULL;
	splits = ft_calloc(ft_wordctd(s, c, &splits) + 1, sizeof(char *));
	if (!splits)
		return (NULL);
	ft_wordctd(s, c, &splits);
	return (splits);
}
