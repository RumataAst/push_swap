/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:37:00 by akretov           #+#    #+#             */
/*   Updated: 2024/04/15 21:08:59 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_st_size(t_list *stack)
{
	int		numbers;
	int		first_value;
	t_list	*current;

	numbers = 0;
	current = stack;
	first_value = stack->value;
	if (stack == NULL)
		return (numbers);
	numbers = 1;
	while (current->next->value != first_value)
	{
		numbers++;
		current = current->next;
	}
	return (numbers);
}

void	ft_error_free(char **array)
{
	free_array(array);
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_error(int i)
{
	if (i == 1)
		write(1, "Error\n", 6);
	exit(1);
}

int	ft_atol(const char *str)
{
	int		sign;
	long	number;

	sign = 1;
	number = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	if (number <= INT_MAX && number >= INT_MIN)
		return (number * sign);
	ft_error(1);
	exit(1);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
