/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:14:39 by akretov           #+#    #+#             */
/*   Updated: 2024/04/14 15:40:31 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_st_min(t_list *lst)
{
	int		min;
	t_list	*start;

	start = lst;
	min = lst->value;
	while (lst->next != start)
	{
		if (min > lst->value)
			min = lst->value;
		lst = lst->next;
	}
	if (min > lst->value)
		min = lst->value;
	return (min);
}

int	ft_st_max(t_list *lst)
{
	int		max;
	t_list	*start;

	start = lst;
	max = lst->value;
	while (lst->next != start)
	{
		if (max < lst->value)
			max = lst->value;
		lst = lst->next;
	}
	if (max < lst->value)
		max = lst->value;
	return (max);
}

int	ft_is_sorted(t_list *stack)
{
	int		temp;
	t_list	*start;

	if (!stack || !stack->next)
		exit (1);
	start = stack;
	temp = stack->value;
	while (stack->next != start)
	{
		if (temp > stack->value)
			return (0);
		temp = stack->value;
		stack = stack->next;
	}
	if (temp > stack->value)
		return (0);
	return (1);
}

void	alg_list_init(t_alg_list *oper)
{
	oper->total = 0;
	oper->ra = 0;
	oper->rb = 0;
	oper->rr = 0;
	oper->rra = 0;
	oper->rrb = 0;
	oper->rrr = 0;
}

void	alg_list_cpy(t_alg_list *dest, const t_alg_list *src)
{
	dest->num_a = src->num_a;
	dest->num_b = src->num_b;
	dest->total = src->total;
	dest->ra = src->ra;
	dest->rb = src->rb;
	dest->rr = src->rr;
	dest->rra = src->rra;
	dest->rrb = src->rrb;
	dest->rrr = src->rrr;
}
