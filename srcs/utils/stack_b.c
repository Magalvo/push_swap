/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:49:54 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/13 17:42:57 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* static void	set_cheapest_b(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	if(!stack)
		return;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_value)
		{
			cheapest_value = stack->cost;
			cheapest_node = stack;
		}
		cheapest_node->cheapest = true;
	}
} */

static void	set_target_b(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->value > b->value
				&& current_a->value < best_match_index)
			{
				best_match_index = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/* t_stack_node *get_best_friend(t_stack_node *a, int value)
{
	int temp;
	t_stack_node *temp_node;

	temp = INT_MAX;
	while (a)
	{
		if (a->value > value && a->value < temp)
		{
			temp = a->value;
			temp_node = a;
		}
		a = a->next;
	}
	return (temp_node);
} */

/* static void set_target_b(t_stack_node *a, t_stack_node *b)
{
	printf("A\n");
	print_list(a);
	printf("B\n");
	print_list(b);
	while (b)
	{
		b->target_node = get_best_friend(a, b->value);
		printf("B = %ld\nBest = %ld\n", b->value, b->target_node->value);
		b = b->next;
	}
	exit(0);
} */

static void cost_analysis_b(t_stack_node *a, t_stack_node *b)
{
	int len_a;
	int len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);

	while (b)
	{
		b->cost = b->index;
		if (!(b->above_median))
			b->cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->cost += b->target_node->index;
		else
			b->cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	push_prep(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void move_b_to_a_fast(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both_b(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) && !(cheapest_node->target_node->above_median))
		reverse_rotate_both_b(a, b, cheapest_node);
	push_prep(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void init_nodes_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
	cost_analysis_b(a, b);
	set_cheapest(b);
}
