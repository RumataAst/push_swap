/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rr_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:58:02 by akretov           #+#    #+#             */
/*   Updated: 2024/04/14 12:24:55 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rr(t_list **stack_1, t_list **stack_2)
{
	if ((*stack_1 == NULL || (*stack_1)->next == NULL)
		|| (*stack_2 == NULL || (*stack_2)->next == NULL))
		return ;
	*stack_1 = (*stack_1)->next;
	*stack_2 = (*stack_2)->next;
	write(1, "rr\n", 3);
}

void	ft_rra(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->prev;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->prev;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_1, t_list **stack_2)
{
	if ((*stack_1 == NULL || (*stack_1)->next == NULL)
		|| (*stack_2 == NULL || (*stack_2)->next == NULL))
		return ;
	*stack_1 = (*stack_1)->prev;
	*stack_2 = (*stack_2)->prev;
	write(1, "rrr\n", 4);
}
