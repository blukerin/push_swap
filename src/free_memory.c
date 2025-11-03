/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:36:55 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/24 13:36:58 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_exit(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
		free_stack(stack_a);
	if (stack_b && *stack_b)
		free_stack(stack_b);
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*next;

	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp != NULL)
	{
		next = tmp->next;
		free (tmp->content);
		free (tmp);
		tmp = next;
	}
	*stack = NULL;
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free (split[i]);
		i++;
	}
	free (split);
}
