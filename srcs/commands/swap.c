/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:40:03 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/08 16:22:55 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void swap(t_stack_node **head) 
{
	t_stack_node *first;
	t_stack_node *second;
	t_stack_node *third;
	
	if (!*head || !(*head)->next)
		return;
	first = *head;
	second = (*head)->next;
	third = second->next;
	second->next = first;
	second->prev = first->prev; 
	first->next = third;
	first->prev = second;
	if (third) 
		third->prev = first; 
	*head = second;
}

void	sa(t_stack_node **a, bool print)
{
	swap(a);
	if (!print)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack_node **b, bool print)
{
	swap(b);
	if (!print)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack_node **a, t_stack_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_putstr_fd("ss\n", 1);
}