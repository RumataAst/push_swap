/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:11:07 by akretov           #+#    #+#             */
/*   Updated: 2024/04/16 18:20:10 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_nums(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && third > first)
		ft_sa(stack);
	else if (first > second && second < third && third < first)
		ft_ra(stack);
	else if (first < second && second > third && third > first)
	{
		ft_sa(stack);
		ft_ra(stack);
	}
	else if (first < second && second > third && third < first)
		ft_rra(stack);
	else if (first > second && second > third)
	{
		ft_sa(stack);
		ft_rra(stack);
	}
}
