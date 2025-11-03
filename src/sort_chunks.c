/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 20:25:44 by bsaldana          #+#    #+#             */
/*   Updated: 2025/11/03 20:25:45 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rb_or_rrb(t_list **stack_b, int size)
{
	int		biggest;
	int		i;
	int		biggest_position;
	t_list	*ptr;

	ptr = *stack_b;
	biggest_position = 0;
	biggest = *((int *)ptr->content);
	i = 0;
	while (ptr != NULL)
	{
		if (*((int *)ptr->content) > biggest)
		{
			biggest = *((int *)ptr->content);
			biggest_position = i;
		}
		ptr = ptr->next;
		i++;
	}
	if (biggest_position > (size / 2))
		return (0);
	else
		return (1);
}

int	is_the_biggest(t_list **stack_b)
{
	t_list	*ptr;
	int		biggest;

	ptr = *stack_b;
	biggest = *((int *)ptr->content);
	while (ptr != NULL)
	{
		if (*((int *)ptr->content) > biggest)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

void	b_to_a(t_list **stack_a, t_list **stack_b)
{
	int	size;

	while (*stack_b != NULL)
	{
		size = ft_lstsize(*stack_b);
		if (is_the_biggest(stack_b))
			pa(stack_b, stack_a);
		else
		{
			if (rb_or_rrb(stack_b, size))
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
}

void	a_to_b(t_list **stack_a, t_list **stack_b, int chunk_size)
{
	int	i;

	i = 0;
	while (*stack_a != NULL)
	{
		if (*((int *)(*stack_a)->content) <= i)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			i++;
		}
		else if (*((int *)(*stack_a)->content) <= i + chunk_size)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	sort_chunk(t_list **stack_a, t_list **stack_b)
{
	int	*copy_stack;
	int	size_a;
	int	chunk_size;

	copy_stack = NULL;
	size_a = ft_lstsize(*stack_a);
	chunk_size = ((ft_sqrt(size_a) * 133) / 100);
	create_array(&copy_stack, stack_a, size_a);
	a_to_b(stack_a, stack_b, chunk_size);
	b_to_a(stack_a, stack_b);
	free(copy_stack);
}
