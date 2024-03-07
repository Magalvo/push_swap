/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:10 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/06 13:57:42 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*push_node;
	
	if(!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if(*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if(!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else 
	{
		push_node->next = *dst;
		(*dst)->prev = push_node;
		*dst = push_node;
	}	
}
void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if(!print)
		ft_putstr_fd("pb\n", 1);
}