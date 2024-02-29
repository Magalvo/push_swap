/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:11:42 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/29 13:23:39 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int	is_deli(char c)
{
	return (c == ' ' || c == '\t');
}

char **aux_func(char *str, char **list, int count)
{
	char	*new_str;
	int		wc;

	new_str = NULL;
	wc = 0;
	while(is_deli(*str))
		str++;
	while(!is_deli(str[wc]) && str[wc])
	if (wc > 0)
		new_str = malloc(sizeof(char) * (wc + 1));
	if(!new_str)
		return (NULL);
	wc = 0;
	while(new_str && !is_deli(*str) && *str)
		new_str[wc++] = *str++;
	if (new_str)
		new_str[wc] = '\0';
	if (new_str)
		aux_func(str, list, count + 1);
	else
		list = malloc(sizeof(char *) * (count +1));
	if(list)
		list[count] = new_str;
	return (list);
}


char	**ft_split(char *str)
{
	return (aux_func(str, NULL, 0));
}
