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
void	stack_args(t_list **stack_a, char *str);
void	free_split(char **split);
void	free_stack(t_list **stack);
void	error_exit(t_list **stack_a, t_list **stack_b);
int		check_duplicates(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	sort_stacks(t_list **stack_a, t_list **stack_b);
void	sort_2(t_list **stack_a);
void	sort_3(t_list **stack);
void	sort_5(t_list **stack_a, t_list **stack_b, int size);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_b, t_list **stack_a);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_b, t_list **stack_a);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
void	sort_chunk(t_list **stack_a, t_list **stack_b);
void	create_array(int **copy, t_list **stack_a, int size);
int		is_sorted(t_list **stack_a);
void	sort_chunk(t_list **stack_a, t_list **stack_b);

#endif
