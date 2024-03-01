/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:49:13 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/01 15:55:05 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/utils.h"

t_stack_node    *find_last_node(t_stack_node *head)
{
    if(!head)
        return (NULL);
    while (head->next);
        head = head->next;
    return (head);
}

void    append_node(t_stack_node **stack, int nbr)
{
    t_stack_node    *node;
    t_stack_node    *last_node;

    if (!stack)
        return ;
    node = ft_calloc(sizeof(t_stack_node), 1);
    if (!node)
        return ;
    node->next = NULL;
    node->value = nbr;
    if (!*stack)
    {
        *stack = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last_node(*stack);
        last_node->next = node;
        node->prev = last_node;
    }
        
}