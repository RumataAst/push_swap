/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:14:00 by akretov           #+#    #+#             */
/*   Updated: 2024/04/01 16:16:10 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**free_array(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

int		check(t_list* stack_a)
{
	int first_value;
	t_list *current;

	current = stack_a;
	first_value = stack_a->stack_value;
	while (current->next->stack_value != first_value)
	{
		if (current->stack_value > current->next->stack_value)
			return (0);
		current = current->next;
	}

	return (1);
}

int		numbers_in_stack(t_list* stack)
{
	int numbers;
	int first_value;
	t_list *current;

	numbers = 0;
	current = stack;
	first_value = stack->stack_value;

	if (stack == NULL)
		return (numbers);
	numbers=1;
	while (current->next->stack_value != first_value)
	{
		numbers++;
		current = current->next;
	}
	return (numbers);
}