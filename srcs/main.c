/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:08:09 by akretov           #+#    #+#             */
/*   Updated: 2024/04/16 18:55:06 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_list(t_list **head)
{
	t_list	*current;
	t_list	*temp;
	t_list	*start;

	if (*head == NULL)
		return ;
	current = *head;
	temp = NULL;
	start = *head;
	while (current->next != start)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	temp = current->next;
	free(current);
	current = temp;
	*head = NULL;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**array;

	stack_b = NULL;
	stack_a = NULL;
	array = ft_check_ac(ac, av);
	stack_a = ft_process(array);
	free_array(array);
	if (ft_is_sorted(stack_a) == 0)
	{
		if (ft_st_size(stack_a) == 2)
			ft_ra(&stack_a);
		else if (ft_st_size(stack_a) == 3)
			sort_three_nums(&stack_a);
		else
			ft_algorithm(&stack_a, &stack_b);
	}
	free_list(&stack_a);
	return (0);
}
