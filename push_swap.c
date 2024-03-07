/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:37:17 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/07 17:39:47 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				len;

	a = NULL;
	b = NULL;
	len = stack_len(a);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac==2)
		av = ft_split(av[1], ' ');
	init_a(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
		if (len == 2)
			sa(&a, false);
		else if (len == 3)
			sort_three(&a);
		//else if (len <= 75);
			//sort_turk(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);	
}