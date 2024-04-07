/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:15:38 by akretov           #+#    #+#             */
/*   Updated: 2024/04/03 17:34:07 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// not checked
void rr(t_list** stack_1, t_list** stack_2)
{
	if ((*stack_1 == NULL || (*stack_1)->next == NULL)
		|| (*stack_2 == NULL || (*stack_2)->next == NULL))
    	return; // If stack_1 is empty or has only one element, nothing to shift

    // Move the head pointer to the next node
    *stack_1 = (*stack_1)->next;
    *stack_2 = (*stack_2)->next;

	write(1,"rr\n", 3);
}

void rra(t_list** stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
    	return; // If stack is empty or has only one element, nothing to shift

    // Move the head pointer to the next node
    *stack = (*stack)->previous;
	write(1,"rra\n", 4);
}

void rrb(t_list** stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
    	return; // If stack is empty or has only one element, nothing to shift

    // Move the head pointer to the next node
    *stack = (*stack)->previous;
	write(1,"rrb\n", 4);
}
// Not checked
void rrr(t_list** stack_1, t_list** stack_2)
{
	if ((*stack_1 == NULL || (*stack_1)->next == NULL)
		|| (*stack_2 == NULL || (*stack_2)->next == NULL))
    	return; // If stack_1 is empty or has only one element, nothing to shift

    // Move the head pointer to the next node
    *stack_1 = (*stack_1)->previous;
    *stack_2 = (*stack_2)->previous;

	write(1,"rrr\n", 4);
}