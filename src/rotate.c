/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:05:43 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/28 18:05:44 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last;
	int		size;

	size = ft_lstsize(*stack);
	if (size < 2)
		return ;
	temp = *stack;
	last = ft_lstlast(*stack);
	*stack = (*stack)->next;
	last->next = temp;
	temp->next = NULL;
}

void	rr(t_list **stack_b, t_list **stack_a)
{
	rotate(stack_b);
	rotate(stack_a);
	ft_printf("rr\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}
