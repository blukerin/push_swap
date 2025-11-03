/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:06:22 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/28 18:06:24 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*temp;
	int		size;

	temp = *stack;
	size = ft_lstsize(*stack);
	if (size < 2)
		return ;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	last = ft_lstlast(*stack);
	temp->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rrr(t_list **stack_b, t_list **stack_a)
{
	reverse_rotate(stack_b);
	reverse_rotate(stack_a);
	ft_printf("rr\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}
