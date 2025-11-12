/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_A.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaldana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:23:04 by bsaldana          #+#    #+#             */
/*   Updated: 2025/10/24 13:23:06 by bsaldana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_duplicates(t_list **stack)
{
	t_list	*ptr;
	t_list	*compare;

	ptr = *stack;
	while (ptr)
	{
		compare = ptr->next;
		while (compare)
		{
			if (*((int *)ptr->content) == (*(int *)compare->content))
				return (0);
			compare = compare->next;
		}
		ptr = ptr->next;
	}
	return (1);
}

static long	ft_atol(char *str, int *err)
{
	long long	r;
	int			i;
	int			s;

	i = 0;
	s = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			*err = 1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	if (r * s > INT_MAX || r * s < INT_MIN || str[i] != '\0')
		*err = 1;
	return (r * s);
}

void	stack_args(t_list **stack_a, char *str)
{
	t_list	*node;
	long	content;
	int		err;
	int		*num;

	err = 0;
	content = ft_atol(str, &err);
	if (err)
		error_exit(stack_a, (t_list **) NULL);
	num = malloc(sizeof(int));
	if (!num)
		error_exit(stack_a, (t_list **) NULL);
	*num = (int)content;
	node = ft_lstnew(num);
	if (!node)
	{
		free(num);
		error_exit(stack_a, (t_list **) NULL);
	}
	ft_lstadd_back(stack_a, node);
}

static int	stack_split_2(t_list **stack_a, char *str)
{
	t_list	*node;
	long	content;
	int		err;
	int		*num;

	err = 0;
	content = ft_atol(str, &err);
	if (err)
		return (0);
	num = malloc(sizeof(int));
	if (!num)
		return (0);
	*num = (int) content;
	node = ft_lstnew(num);
	if (!node)
	{
		free(num);
		return (0);
	}
	ft_lstadd_back(stack_a, node);
	return (1);
}

void	stack_split(t_list **stack_a, char *str)
{
	char	**numbers;
	int		i;

	i = 0;
	numbers = ft_split(str, ' ');
	if (!numbers)
		return ;
	while (numbers[i] != NULL)
	{
		if (!stack_split_2(stack_a, numbers[i]))
		{
			free_split(numbers);
			error_exit(stack_a, (t_list **) NULL);
		}
		i++;
	}
	free_split(numbers);
	return ;
}
