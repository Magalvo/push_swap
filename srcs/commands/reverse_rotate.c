/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:39:37 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/07 19:07:34 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*second_to_last;
	t_stack_node	*last;

	if(!*stack || !(*stack)->next)
		return ;
	last = *stack;
	second_to_last = NULL;
	while (last->next)
	{
		second_to_last = last;
		last = last->next;
	}
	if (second_to_last)
		second_to_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if(!print)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if(!print)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if(!print)
		ft_putstr_fd("rrr\n", 1);
}

void	reverse_rotate_both(t_stack_node **a, t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
			&& *a != cheapest_node)
	{
		rrr(a, b, false);
	}
			
	current_index(*a);
	current_index(*b);
}