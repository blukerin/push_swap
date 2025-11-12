/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_force.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:07:11 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/28 18:07:15 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	little_to_b(t_list **stack_a, t_list **stack_b, int size, int i)
{
	int		little;
	int		little_pos;
	t_list	*tmp;

	tmp = *stack_a;
	little_pos = 0;
	little = *((int *)tmp->content);
	while (tmp != NULL)
	{
		if (little > *((int *)tmp->content))
		{
			little = *((int *)tmp->content);
			little_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	while ((*(int *)(*stack_a)->content) != little)
	{
		if (little_pos < (size / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b, int size)
{
	int		i;
	t_list	*tmp;

	tmp = *stack_a;
	while (size > 3)
	{
		i = 0;
		little_to_b(stack_a, stack_b, size, i);
		size--;
	}
	sort_3(stack_a);
	while (*stack_b != NULL)
	{
		pa(stack_b, stack_a);
		if (*(int *)(*stack_a)->content > *(int *)(*stack_a)->next->content)
			sa(stack_a);
	}
}

void	sort_3(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = *(int *)(*stack)->content;
	second = *(int *)(*stack)->next->content;
	third = *(int *)(*stack)->next->next->content;
	if (first > second && first < third)
		sa(stack);
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first > third && second < third)
		ra(stack);
	else if (first < second && first > third)
		rra(stack);
	else if (first < second && second > third)
	{
		sa(stack);
		ra(stack);
	}
}

void	sort_2(t_list **stack_a)
{
	if (*(int *)(*stack_a)->content > (*(int *)(*stack_a)->next->content))
		sa(stack_a);
}
