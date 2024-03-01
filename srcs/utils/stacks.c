/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:06:09 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/01 15:48:08 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

int	stack_len(t_stack_node *stack)
{

}

bool	stack_sorted(t_stack_node *stack)
{
	
}

void    stack_init(t_stack_node **a, char **argv, bool flag_argc_2)
{
    long    nbr;
    while(*argv)
    {
        nbr = ft_atol(*argv);
        if (nbr > INT_MAX || nbr < INT_MIN)
            error_free(a, argv, flag_argc_2);
        if (error_repetition(*a, (int)nbr))
            error_free(a, argv, flag_argc_2);
        append_node(a, (int)nbr);
        ++i;
    }
    if (flag_argc_2)
        free_matrix(argv);
}
