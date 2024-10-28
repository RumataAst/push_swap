/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:35:58 by akretov           #+#    #+#             */
/*   Updated: 2024/04/14 14:21:37 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	close_l_num(t_list *stack, int desired_num)
{
	int		closest_lower;
	t_list	*start;

	start = stack;
	closest_lower = INT_MIN;
	while (stack != NULL)
	{
		if (desired_num > stack->value && stack->value > closest_lower)
			closest_lower = stack->value;
		stack = stack->next;
		if (stack == start)
			break ;
	}
	return (closest_lower);
}

int	close_h_num(t_list *stck, int desired_num)
{
	int		closest_higher;
	t_list	*start;

	start = stck;
	closest_higher = INT_MAX;
	while (stck)
	{
		if (desired_num < stck->value && stck->value < closest_higher)
			closest_higher = stck->value;
		stck = stck->next;
		if (stck == start)
			break ;
	}
	return (closest_higher);
}

void	ra_rb_is_lowest(t_alg_list *possblts, int ra_rb_oper)
{
	if (possblts->ra >= possblts->rb)
	{
		possblts->total = ra_rb_oper;
		possblts->rr = possblts->rb;
		possblts->ra = possblts->ra - possblts->rb;
		possblts->rb = 0;
		possblts->rra = 0;
		possblts->rrb = 0;
	}
	else
	{
		possblts->total = ra_rb_oper;
		possblts->rr = possblts->ra;
		possblts->rb = possblts->rb - possblts->ra;
		possblts->ra = 0;
		possblts->rra = 0;
		possblts->rrb = 0;
	}
}

void	rra_rrb_is_lowest(t_alg_list *possblts, int rra_rrb_oper)
{
	if (possblts->rra >= possblts->rrb)
	{
		possblts->total = rra_rrb_oper;
		possblts->ra = 0;
		possblts->rb = 0;
		possblts->rrr = possblts->rrb;
		possblts->rra = possblts->rra - possblts->rrb;
		possblts->rrb = 0;
	}
	else
	{
		possblts->total = rra_rrb_oper;
		possblts->ra = 0;
		possblts->rb = 0;
		possblts->rrr = possblts->rra;
		possblts->rrb = possblts->rrb - possblts->rra;
		possblts->rra = 0;
	}
}
