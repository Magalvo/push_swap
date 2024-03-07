/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:07:50 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/07 18:42:47 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;
	
	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
			&& !(cheapest_node->target_node->above_median))
			reverse_rotate_both(a, b, cheapest_node);
	push_prep(a, cheapest_node, 'a');
	push_prep(b, cheapest_node->target_node, 'b');
	pb(b, a, false);			
}

void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	push_prep(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack_node **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

