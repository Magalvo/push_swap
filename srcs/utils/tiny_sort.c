/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:43:47 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/13 18:48:49 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node *biggest_node;

	biggest_node = find_max(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}
/* void	sort_ten(t_stack_node *a, t_stack_node *b)
{
	int	len;

	t_stack_node *small;
	t_stack_node *first;

	first = find_min(a);
	if (stack_len(a) <= 3)
		sort_three(a);
	else
	{
		if (stack_len(a) / 2 > )
	}
} */
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
