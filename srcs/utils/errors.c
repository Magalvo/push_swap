/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:38:29 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/07 16:23:23 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_matrix(char **argv)
{
	int i;
	i = -1;
	if(NULL == argv || NULL == *argv)
		return ;
	while (argv[i++])
		free(argv[i++]);
	free(argv - 1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node    *tmp;
	t_stack_node    *current;

	if(!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error_syntax(char *str_nbr)
{
	if(!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
			return (ft_putstr_fd("Error\n", 2), 1);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
			&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
			return (ft_putstr_fd("Error\n", 2), 1);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	return (0);
} 

int	error_repetition(t_stack_node *a, int nbr)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (ft_putstr_fd("Error\n", 2), 1);
		a = a->next;
	}
	return (0);
}

void    error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
	free_stack(a);
	if(flag_argc_2)
		free_matrix(argv);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}