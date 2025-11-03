/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:04:10 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/28 18:04:11 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_list **stack)
{
	t_list	*ptr1;
	t_list	*ptr2;
	int		temp;

	if (!*stack || !(*stack)->next)
		return ;
	ptr1 = *stack;
	ptr2 = (*stack)->next;
	temp = *(int *)ptr1->content;
	*(int *)ptr1->content = *(int *)ptr2->content;
	*(int *)ptr2->content = temp;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

void	sb(t_list **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	sa(t_list **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}
