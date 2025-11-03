/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:17:35 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/30 12:17:36 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	index_stack(t_list **stack_a, int **arr, int size)
{
	t_list	*ptr;
	int		i;

	ptr = *stack_a;
	while (ptr != NULL)
	{
		i = 0;
		while (i < size)
		{
			if ((*arr)[i] == *((int *)ptr->content))
			{
				*((int *)ptr->content) = i;
				break ;
			}
			i++;
		}
		ptr = ptr->next;
	}
}

static void	order_array(int	*copy, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (copy[i] > copy[i + 1])
		{
			tmp = copy[i];
			copy[i] = copy[i + 1];
			copy[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void	create_array(int **arr, t_list **stack_a, int size)
{
	t_list	*ptr;
	int		i;

	ptr = *stack_a;
	i = 0;
	*arr = malloc(size * sizeof(int));
	if (!*arr)
		return ;
	while (ptr != NULL)
	{
		(*arr)[i] = *((int *)ptr->content);
		ptr = ptr->next;
		i++;
	}
	order_array(*arr, size);
	index_stack(stack_a, arr, size);
}
