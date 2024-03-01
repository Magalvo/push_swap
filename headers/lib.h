/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:56:13 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/01 15:57:26 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

#include "push_swap.h"
#include "utils.h"
#include "commands.h"

char			**ft_split(char const *s, char c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_calloc(size_t count, size_t size);
int				ft_putstr_fd(char *s, int fd);
static long		ft_atol(const char *str);

#endif