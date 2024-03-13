/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:11:43 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/12 18:37:36 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	bubble_sort(long arr[], int n)
{
	int		i;
	int 	j;
	long	temp;

	i = 0;
	while (i < n-1)
	{
		j = 0;
		while (j < n-i-1)
		{
			if (arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	assign_ranks(t_stack_node *head, long sorted_values[], int len)
{
	t_stack_node	*current;
	int				i;

	current = head;
	while (current != NULL)
	{
		i = 0;
		while(i < len)
		{
			if (current->value == sorted_values[i])
			{
				current->rank = i + 1;
				break;
			}
			i++;
		}
		current = current->next;
	}
}

int	ranking(t_stack_node **stack)
{
	int				len;
	int				index;
	long			*arr;
	t_stack_node	*current;

	index = 0;
	current = *stack;
	len = stack_len(*stack);
	arr = malloc(sizeof(long) * len);
	while (current != NULL)
	{
		arr[index++] = current->value;
		current = current->next;
	}
	bubble_sort(arr, len);
	assign_ranks(*stack, arr, len);
	free(arr);
	return (0);
}
