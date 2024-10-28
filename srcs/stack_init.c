/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 12:52:56 by akretov           #+#    #+#             */
/*   Updated: 2024/04/14 14:22:10 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*create_node(char *value)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		exit(1);
	new_node->value = ft_atol(value);
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	ft_connect_2_nodes(t_list *first, t_list *second)
{
	first->next = second;
	first->prev = second;
	second->next = first;
	second->prev = first;
}

void	ft_connect_plus_one(t_list *stack, t_list *new_node)
{
	new_node->prev = stack->prev;
	new_node->next = stack;
	stack->prev->next = new_node;
	stack->prev = new_node;
}

t_list	*ft_process(char **array)
{
	t_list	*stack_a;
	t_list	*new_node;
	int		i;

	i = 0;
	stack_a = NULL;
	new_node = NULL;
	while (array[i])
	{
		new_node = create_node(array[i]);
		if (!stack_a)
			stack_a = new_node;
		else if (!stack_a->next)
			ft_connect_2_nodes(stack_a, new_node);
		else
			ft_connect_plus_one(stack_a, new_node);
		i++;
	}
	return (stack_a);
}
