/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:42:16 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/08 15:34:35 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_a(t_stack_node	**a, char **av, bool flag)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			error_free(a, av, flag);
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, av, flag);
		if (error_repetition(*a, (int)nbr))
		{
			printf("Repetition\n");
			error_free(a, av, flag);
		}
		append_node(a, (int)nbr);
		i++;
	}
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if(!stack)
		return (NULL);
	while(stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return(NULL);
}

void	push_prep(t_stack_node **stack, t_stack_node *top_node, char stk_name)
{
	while (*stack != top_node)
	{
		if (stk_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stk_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}	
	}	
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{	
	int	len_a;
	
	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}