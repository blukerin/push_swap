/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:09:20 by bsaldana          #+#    #+#             */
/*   Updated: 2025/11/03 16:09:21 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_stacks(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
		sort_2(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4 || size == 5)
		sort_5(stack_a, stack_b, size);
	else
		sort_chunk(stack_a, stack_b);
}

int	is_sorted(t_list **stack_a)
{
	t_list	*ptr;
	t_list	*next;

	ptr = *stack_a;
	while (ptr)
	{
		next = ptr->next;
		while (next)
		{
			if (*((int *)ptr->content) > (*(int *)next->content))
				return (0);
			next = next->next;
		}
		ptr = ptr->next;
	}
	return (1);
}
