/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   han_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:12:26 by akretov           #+#    #+#             */
/*   Updated: 2024/04/16 17:02:50 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_check_unique(char **array)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_strncmp(array[i], array[j], ft_strlen(array[j]) + 1) == 0)
				ft_error_free(array);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_errors(char **array)
{
	int	i;
	int	j;

	j = 0;
	while (array[j])
	{
		i = 0;
		while (array[j][i])
		{
			if (!(ft_isdigit(array[j][i])
				|| ((i == 0 && array[j][i] == '-'
					&& ft_isdigit(array[j][i + 1]))
				|| (i == 0 && array[j][i] == '+'
					&& ft_isdigit(array[j][i + 1])))))
				ft_error_free(array);
			i++;
		}
		j++;
	}
	if (ft_check_unique(array) == 1)
		return (1);
	return (0);
}

char	**get_values_from_argv(int ac, char **av)
{
	int		i;
	char	**array;

	i = 1;
	array = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!array)
		return (NULL);
	while (i < ac)
	{
		array[i - 1] = ft_strdup(av[i]);
		if (!array[i - 1])
		{
			free_array(array);
			return (NULL);
		}
		i++;
	}
	array[i] = "\0";
	return (array);
}

char	**ft_check_ac(int ac, char **av)
{
	char	**array;

	if (ac == 1)
		exit (1);
	else if (ac == 2)
		array = ft_split(av[1], ' ');
	else if (ac > 2)
		array = get_values_from_argv(ac, av);
	else
	{
		array = NULL;
		ft_error_free(array);
	}
	ft_check_errors(array);
	if (!array[0])
		ft_error_free(array);
	return (array);
}
