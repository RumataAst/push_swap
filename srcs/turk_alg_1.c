/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:01:42 by akretov           #+#    #+#             */
/*   Updated: 2024/04/16 18:35:56 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rx_operations(t_alg_list *possibilities)
{
	if (possibilities->ra >= possibilities->rb)
		return (possibilities->ra);
	else
		return (possibilities->rb);
}

int	rrx_operations(t_alg_list *possibilities)
{
	if (possibilities->rra >= possibilities->rrb)
		return (possibilities->rra);
	else
		return (possibilities->rrb);
}

void	numof_r_rr_moves(t_list *stck, int num_to_move, int *rx, int *rrx)
{
	int		numof_rx;
	int		numof_rrx;
	int		before_num_to_find;
	t_list	*start;

	start = stck;
	before_num_to_find = 1;
	numof_rx = 0;
	numof_rrx = 0;
	while (stck)
	{
		if (stck->value == num_to_move)
			before_num_to_find = 0;
		else if (before_num_to_find == 1)
			numof_rx++;
		else
			numof_rrx++;
		stck = stck->next;
		if (stck == start)
			break ;
	}
	if (numof_rx > 0 || numof_rrx > 0)
		numof_rrx++;
	*rx = numof_rx;
	*rrx = numof_rrx;
}

void	pick_lowest(t_alg_list *possblts)
{
	int	rra_rb;
	int	ra_rrb;
	int	ra_rb;
	int	rra_rrb;

	ra_rb = rx_operations(possblts);
	ra_rrb = possblts->ra + possblts->rrb;
	rra_rb = possblts->rra + possblts->rb;
	rra_rrb = rrx_operations(possblts);
	if (ra_rb <= ra_rrb && ra_rb <= rra_rb && ra_rb <= rra_rrb)
		ra_rb_is_lowest(possblts, ra_rb);
	else if (rra_rrb <= ra_rb && rra_rrb <= ra_rrb && rra_rrb <= rra_rb)
		rra_rrb_is_lowest(possblts, rra_rrb);
	else if (ra_rrb <= ra_rb && ra_rrb <= rra_rb && ra_rrb <= rra_rrb)
	{
		possblts->total = ra_rrb;
		possblts->rra = 0;
		possblts->rb = 0;
	}
	else if (rra_rb <= ra_rb && rra_rb <= ra_rrb && rra_rb <= rra_rrb)
	{
		possblts->total = rra_rb;
		possblts->ra = 0;
		possblts->rrb = 0;
	}
}

void	get_numof_opers(t_alg_list	*oper, t_list *stck_a, t_list *stck_b)
{
	alg_list_init(oper);
	numof_r_rr_moves(stck_a, oper->num_a, &oper->ra, &oper->rra);
	numof_r_rr_moves(stck_b, oper->num_b, &oper->rb, &oper->rrb);
	pick_lowest(oper);
}
