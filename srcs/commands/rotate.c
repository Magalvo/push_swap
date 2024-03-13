/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:17:24 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/13 14:27:31 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	t_stack_node	*first;

	if(!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last = first;
	while(last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if(!print)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if(!print)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if(!print)
		ft_putstr_fd("rr\n", 1);
}
void	rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node
			&& *a != cheapest_node)
			rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	rotate_both_b(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node
			&& *b != cheapest_node)
			rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
