/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:19:49 by bsaldana          #+#    #+#             */
/*   Updated: 2025/06/16 19:19:51 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"
# include <limits.h>

void	stack_split(t_list **stack_a, char *str);
int		stack_split_2(t_list **stack_a, char *str);
void	stack_args(t_list **stack_a, char *str);
long	ft_atol(char *str, int *err);
void	free_split(char **split);
void	free_stack(t_list **stack);
void	error_exit(t_list **stack_a, t_list **stack_b);
int		check_duplicates(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	swap(t_list **stack);
void	sort_stacks(t_list **stack_a, t_list **stack_b);
void	sort_2(t_list **stack_a);
void	sort_3(t_list **stack);
void	sort_5(t_list **stack_a, t_list **stack_b, int size);
void	little_to_b(t_list **stack_a, t_list **stack_b, int size, int i);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_b, t_list **stack_a);
void	rotate(t_list **stack);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_b, t_list **stack_a);
void	reverse_rotate(t_list **stack);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	push(t_list **src, t_list **dst);
void	sort_chunk(t_list **stack_a, t_list **stack_b);
void	create_array(int **copy, t_list **stack_a, int size);
int		is_sorted(t_list **stack_a);
void	sort_chunk(t_list **stack_a, t_list **stack_b);
void	a_to_b(t_list **stack_a, t_list **stack_b, int chunk_size);
void	b_to_a(t_list **stack_a, t_list **stack_b);
int		is_the_biggest(t_list **stack_b);
int		rb_or_rrb(t_list **stack_b, int size);

#endif
