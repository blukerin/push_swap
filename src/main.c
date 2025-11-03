/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 19:17:47 by bsaldana          #+#    #+#             */
/*   Updated: 2025/06/16 19:17:49 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (argc == 2)
			stack_split(&stack_a, argv[1]);
		else
		{
			while (argv[i] != NULL)
				stack_args(&stack_a, argv[i++]);
		}
		if (!check_duplicates(&stack_a))
			error_exit(&stack_a, (t_list **) NULL);
		if (!is_sorted(&stack_a))
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
