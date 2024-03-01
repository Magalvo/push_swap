/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:11:10 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/01 14:20:04 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pos;
	unsigned char	ac;

	ac = (unsigned char)c;
	pos = (unsigned char *)b;
	while (len--)
		*pos++ = ac;
	return (b);
}
