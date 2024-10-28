/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_sa_ra_0.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 14:15:09 by akretov           #+#    #+#             */
/*   Updated: 2024/04/12 14:23:12 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ra(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	write(1, "rb\n", 3);
}

void	ft_sa(t_list **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL
		|| (*stack)->next->next == NULL)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack)
{
	int	temp;

	if (*stack == NULL || (*stack)->next == NULL
		|| (*stack)->next->next == NULL)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_list **stack_1, t_list **stack_2)
{
	int	temp;

	if ((*stack_1 == NULL || (*stack_1)->next == NULL
			|| (*stack_1)->next->next == NULL)
		|| (*stack_2 == NULL || (*stack_2)->next == NULL
			|| (*stack_2)->next->next == NULL))
		return ;
	temp = (*stack_1)->value;
	(*stack_1)->value = (*stack_1)->next->value;
	(*stack_1)->next->value = temp;
	temp = (*stack_2)->value;
	(*stack_2)->value = (*stack_2)->next->value;
	(*stack_2)->next->value = temp;
	write(1, "ss\n", 3);
}
