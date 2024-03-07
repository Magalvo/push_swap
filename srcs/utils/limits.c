/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   limits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 21:03:14 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/07 16:33:52 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	ctd;
	
	if (!stack)
		return (0);
	ctd = 0;
	while (stack)
	{
		stack->index = ctd;
		stack = stack->next;
		ctd++;
	}
	return (ctd);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while(stack->next)
		stack = stack->next;
	return (stack);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;
	long			max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if(stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*node;
	long			min;

	min = LONG_MAX;
	if(!stack)
		return (0);
	while(stack)
	{
		if(stack->value < min)
		{
			min = stack->value;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return  (true);
}