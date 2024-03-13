/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:49:53 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/13 14:23:32 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node 	*target_node;
	long			best_match_index;

	while (a)
	{
		best_match_index = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->value < a->value
				&& current_b->value > best_match_index)
				{
					best_match_index = current_b->value;
					target_node = current_b;
				}
				current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	cost_analysis_a(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->cost = a->index;
		if (!(a->above_median))
			a->cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->cost += a->target_node->index;
		else
			a->cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

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

void	init_nodes_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis_a(a, b);
	set_cheapest(a);
}
