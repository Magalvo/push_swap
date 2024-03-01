/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:11:05 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/01 15:57:48 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "push_swap.h"
#include "commands.h"
#include "lib.h"

//===========================Stack Initiation=========================//

//============================Handle Errors===========================//

void	free_matrix(char **argv);
void	free_stack(t_stack_node **stack);
void    error_free(t_stack_node **a, char **argv, bool flag_argc_2);
int		error_syntax(char *str_nbr);
int		error_repetition(t_stack_node *a, int nbr);

#endif