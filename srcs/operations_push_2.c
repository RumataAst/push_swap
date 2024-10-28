/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:29:57 by akretov           #+#    #+#             */
/*   Updated: 2024/04/16 17:23:42 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_pa_last(t_list **stck_b, t_list **stck_a, int *num_b, int *num_a)
{
	t_list	*new_node;
	t_list	*top_stack_a;
	t_list	*second_of_stack_b;

	new_node = *stck_b;
	top_stack_a = *stck_a;
	second_of_stack_b = (*stck_b)->next;
	if (*stck_b == NULL)
		return ;
	if ((*stck_b)->next == NULL || (*stck_b)->next == *stck_b)
		*stck_b = NULL;
	else
	{
		second_of_stack_b->prev->prev->next = second_of_stack_b;
		second_of_stack_b->prev = second_of_stack_b->prev->prev;
		*stck_b = (*stck_b)->next;
	}
	new_node->prev = top_stack_a->prev;
	new_node->next = top_stack_a;
	top_stack_a->prev->next = new_node;
	top_stack_a->prev = new_node;
	*stck_a = (*stck_a)->prev;
	num_b--;
	num_a++;
	write(1, "pa\n", 3);
}

void	ft_push(t_list **stack_1, t_list **stack_2, int *num_1, int *num_2)
{
	t_list	*new_node;
	t_list	*top_stack_b;

	new_node = *stack_1;
	top_stack_b = *stack_2;
	*stack_1 = (*stack_1)->next;
	(*stack_1)->prev = new_node->prev;
	new_node->prev->next = *stack_1;
	if (top_stack_b == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
	}
	else if (top_stack_b->next == NULL)
		ft_connect_2_nodes(top_stack_b, new_node);
	else
		ft_connect_plus_one(top_stack_b, new_node);
	*stack_2 = new_node;
	(*num_1)--;
	(*num_2)++;
}

void	ft_pa(t_list **stack_b, t_list **stack_a, int *num_b, int *num_a)
{
	ft_push(stack_b, stack_a, num_b, num_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_list **stack_a, t_list **stack_b, int *num_a, int *num_b)
{
	ft_push(stack_a, stack_b, num_a, num_b);
	write(1, "pb\n", 3);
}
