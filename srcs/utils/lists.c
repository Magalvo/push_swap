/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:54 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/13 17:51:05 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


void	print_list(t_stack_node *stack)
{
	while (stack)
	{
		printf("Value: %ld\n", stack->value);
		stack = stack->next;
	}
}

void	print_ranks(t_stack_node *stack)
{
	while (stack)
	{
		printf("Value: %d\n", stack->rank);
		stack = stack->next;
	}
}
