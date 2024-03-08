/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-maga <dde-maga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:26:16 by dde-maga          #+#    #+#             */
/*   Updated: 2024/03/08 18:35:58 by dde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_stack_node t_stack_node;

struct s_stack_node
{
	int		cost;
	int 	rank;
	long	value;
	long	index;
	bool	cheapest;
	bool	above_median;
	struct	s_stack_node *next;
	struct	s_stack_node *prev;
	struct	s_stack_node *target_node;
};

//=====================Commands=====================//
//			    Push
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);

//				Swap
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);

//				Rotate
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			rotate_both(t_stack_node **a, t_stack_node **b,
								t_stack_node *cheapest_node);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
								t_stack_node *cheapest_node);

//=======================Moves==========================//
void			push_prep(t_stack_node **stack, t_stack_node *top_node, char stk_name);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			min_on_top(t_stack_node **a);

//======================Sort======================//
void			sort_three(t_stack_node **a);

//======================Errors & Cleaning ======================//
void			error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack_node **stack, char **av, bool flag);
void			free_all(char **in);
int				error_syntax(char *str_nbr);
int				error_repetition(t_stack_node *a, int nbr);

//======================Stacks======================//
void			init_a(t_stack_node	**a, char **av, bool flag);
int				ranking(t_stack_node **stack);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
int				stack_len(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);

//======================Nodes======================//
void			append_node(t_stack_node **stack, int n);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);

//======================Costs======================//
void			set_cheapest(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

//======================Lib======================//
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t count, size_t size);
char			**ft_split(char const *s, char c);
char			*ft_strdup(char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
long			ft_atol(const char *str);

#endif