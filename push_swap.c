/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:37:17 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/13 17:45:20 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"


int	main(int ac, char **av)
{
	static t_stack_node	*a;
	static t_stack_node	*b;

	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	if (ac==2)
		av = ft_split(av[1], ' ');
	init_a(&a, av + 1, ac == 2);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		/* else if (stack_len(a) <= 75)
			sort_stacks(&a, &b); */
		else
			fast_sort(&a, &b);
	}
	free_stack(&a, av, ac == 2);
	return (0);
}
