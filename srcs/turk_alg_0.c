/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_alg_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:12:35 by akretov           #+#    #+#             */
/*   Updated: 2024/04/16 18:37:16 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	find_best_to_push(t_list **st_a, t_list **st_b, int *s_a, int *s_b)
{
	t_alg_list	lowest_possblts;
	t_alg_list	temp_alg;
	int			num;
	t_list		*temp;

	if (*st_a == NULL)
		return ;
	alg_list_init(&lowest_possblts);
	lowest_possblts.total = INT_MAX;
	temp = *st_a;
	while (temp != NULL && temp->next != *st_a)
	{
		num = temp->value;
		temp_alg.num_a = num;
		if (num < ft_st_min(*st_b) || num > ft_st_max(*st_b))
			temp_alg.num_b = ft_st_max(*st_b);
		else
			temp_alg.num_b = close_l_num(*st_b, num);
		get_numof_opers(&temp_alg, *st_a, *st_b);
		if (temp_alg.total < lowest_possblts.total)
			alg_list_cpy(&lowest_possblts, &temp_alg);
		temp = temp->next;
	}
	do_operations(&lowest_possblts, st_a, st_b);
	ft_pb(st_a, st_b, s_a, s_b);
}

static void	push_all_to_b(t_list **s_a, t_list **s_b, int *size_a, int *size_b)
{
	if (*size_a == 4)
		ft_pb(s_a, s_b, size_a, size_b);
	else
	{
		ft_pb(s_a, s_b, size_a, size_b);
		ft_pb(s_a, s_b, size_a, size_b);
	}
	while (*size_a > 3)
		find_best_to_push(s_a, s_b, size_a, size_b);
}

static void	push_all_to_a(t_list **st_a, t_list **st_b, int *s_a, int *s_b)
{
	int			cl_h_num;
	t_alg_list	possblts;
	t_list		*start;

	start = *st_b;
	while (*st_b)
	{
		alg_list_init(&possblts);
		if ((*st_b)->value > ft_st_max(*st_a))
			cl_h_num = ft_st_min(*st_a);
		else
			cl_h_num = close_h_num(*st_a, (*st_b)->value);
		numof_r_rr_moves(*st_a, cl_h_num, &possblts.ra, &possblts.rra);
		if (possblts.ra <= possblts.rra)
			possblts.rra = 0;
		else
			possblts.ra = 0;
		do_operations(&possblts, st_a, st_b);
		ft_pa_last(st_b, st_a, s_b, s_a);
		if (*st_b == start || *st_b == NULL || s_b == 0)
			break ;
	}
}

static void	last_sort(t_list **stck_a)
{
	t_alg_list	possblts;

	alg_list_init(&possblts);
	possblts.num_a = ft_st_min(*stck_a);
	numof_r_rr_moves(*stck_a, possblts.num_a, &possblts.ra, &possblts.rra);
	if (possblts.ra <= possblts.rra)
		possblts.rra = 0;
	else
		possblts.ra = 0;
	do_operations(&possblts, stck_a, NULL);
}

void	ft_algorithm(t_list **stack_a, t_list **stack_b)
{
	int		size_a;
	int		size_b;

	size_a = ft_st_size(*stack_a);
	size_b = 0;
	push_all_to_b(stack_a, stack_b, &size_a, &size_b);
	sort_three_nums(stack_a);
	push_all_to_a(stack_a, stack_b, &size_a, &size_b);
	last_sort(stack_a);
}
