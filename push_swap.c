/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:19:56 by akretov           #+#    #+#             */
/*   Updated: 2024/02/05 18:33:29 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		count;
	const char	*src_1;
	char		*dest_1;

	count = 0;
	dest_1 = dest;
	src_1 = src;
	if (!dest && !src)
		return (NULL);
	while (count < n)
	{
		dest_1[count] = src_1[count];
		count++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	size_t		i;
	char		*copy_str;

	i = ft_strlen(s);
	copy_str = (char *)malloc(sizeof (char) * i + 1);
	if (copy_str == NULL)
		return (0);
	ft_memcpy(copy_str, s, i);
	copy_str[i] = '\0';
	return (copy_str);
}

char **get_values_from_argv(int argc, char **argv)
{
    int i;

	i = 1;
	char **split_args = (char **)malloc(sizeof(char *) * argc);
    if (!split_args)
        return NULL;
    while (i < argc)
    {
        split_args[i - 1] = ft_strdup(argv[i]);
        if (!split_args[i - 1])
        {
            free_array(split_args, i - 1);
            return NULL;
        }
        i++;
    }
	split_args[i] = "\0";
    return (split_args);
}

int	main(int ac, char **av)
{
	t_list *stack_a;
	char	**split_values;

	if (ac <= 1)
	{
		printf("Error, add values for stack a");
		return (-1);
	}
	else if (ac == 2)
		split_values = ft_split(av[1], ' ');
	else
		split_values = get_values_from_argv(ac, av);

	int p = 0;
	while (split_values[p])
	{
		printf("Number: %s\n", split_values[p]);
		p++;
	}
	if (ft_check_errors(split_values) == -1)
		return (-1);
    stack_a = ft_transform_to_stack(split_values);
	printf("Transformation is working\n");
	while (stack_a)
	{
		printf("First number %i\n", stack_a->stack_value);
		stack_a = stack_a->next;
	}
	free_array(split_values, ac);
	// push_swap(stack_a, stack_b);
	return (0);
}
