/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:03:49 by dde-maga          #+#    #+#             */
/*   Updated: 2024/02/29 18:16:57 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdbool.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_struct_a t_struct_a;
typedef struct s_struct_b t_struct_b;
typedef struct s_stack_node t_stack_node;

struct s_stack_node
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	t_stack_node	*target_node;
	t_stack_node	*next;
	t_stack_node	*prev;
};

//============================Handle Errors===========================//

//===========================Stack Initiation=========================//

//===========================Nodes Initiation=========================//

//=============================Stack Utils============================//
void	sort_three(t_stack_node **a);
//==============================Commands==============================//

//=============================Algorithms============================//














#endif
