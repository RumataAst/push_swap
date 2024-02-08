/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:46:48 by akretov           #+#    #+#             */
/*   Updated: 2024/02/06 15:29:41 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int ft_check_unique(char **split_values)
{
    size_t i = 0;
    size_t j;

    while (split_values[i])
    {
        j = i + 1;
        while (split_values[j])
        {
            if (ft_strncmp(split_values[i], split_values[j], ft_strlen(split_values[j]) + 1) == 0)
            {
                printf("Algorithm only works with unique numbers");
                return (-1);
            }
            j++;
        }
        i++;
	}
    return (0);
}

int	ft_check_errors(char **split_values)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (split_values[j])
	{
		i = 0;
		while (split_values[j][i])
		{
            if (!(ft_isdigit(split_values[j][i]) || (i == 0 && split_values[j][i] == '-' && ft_isdigit(split_values[j][i+1]))))
			{
	           printf("Algorithm only works with numbers");
				return (-1);
			}
			i++;
		}
		j++;
	}
	if (ft_check_unique(split_values) == -1)
		return (-1);
	return (0);
}
