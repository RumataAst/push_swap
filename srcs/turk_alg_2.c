/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:18:51 by akretov           #+#    #+#             */
/*   Updated: 2024/04/16 18:37:06 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	do_operations(t_alg_list *best_ch, t_list **stck_a, t_list **stck_b)
{
	int	i;

	i = 0;
	while (i++ < best_ch->ra)
		ft_ra(stck_a);
	i = 0;
	while (i++ < best_ch->rb)
		ft_rb(stck_b);
	i = 0;
	while (i++ < best_ch->rr)
		ft_rr(stck_a, stck_b);
	i = 0;
	while (i++ < best_ch->rra)
		ft_rra(stck_a);
	i = 0;
	while (i++ < best_ch->rrb)
		ft_rrb(stck_b);
	i = 0;
	while (i++ < best_ch->rrr)
		ft_rrr(stck_a, stck_b);
}
