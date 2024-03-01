/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:11:15 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/01 14:19:58 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*out;

	out = malloc(nmemb * size);
	if (out == NULL)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (out);
	ft_memset(out, 0, nmemb * size);
	return (out);
}