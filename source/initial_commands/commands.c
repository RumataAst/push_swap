/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:10:18 by akretov           #+#    #+#             */
/*   Updated: 2024/04/03 16:22:14 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

void ra(t_list** stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
    	return; // If stack is empty or has only one element, nothing to shift

    // Move the head pointer to the next node
    *stack = (*stack)->next;
	write(1,"ra\n", 3);
}

void rb(t_list** stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
    	return; // If stack is empty or has only one element, nothing to shift

    // Move the head pointer to the next node
    *stack = (*stack)->next;
	write(1,"rb\n", 3);
}

void sa(t_list** stack)
{
    if (*stack == NULL || (*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    // Swap the values of the first two elements
    int temp = (*stack)->stack_value;
    (*stack)->stack_value = (*stack)->next->stack_value;
    (*stack)->next->stack_value = temp;
	write(1,"sa\n", 3);
}

void sb(t_list** stack)
{
    if (*stack == NULL || (*stack)->next == NULL || (*stack)->next->next == NULL)
        return;

    // Swap the values of the first two elements
    int temp = (*stack)->stack_value;
    (*stack)->stack_value = (*stack)->next->stack_value;
    (*stack)->next->stack_value = temp;
	write(1,"sb\n", 3);
}

// Not checked
void ss(t_list** stack_1, t_list**stack_2)
{
    int temp;
	
	if ((*stack_1 == NULL || (*stack_1)->next == NULL || (*stack_1)->next->next == NULL) 
		|| (*stack_2 == NULL || (*stack_2)->next == NULL || (*stack_2)->next->next == NULL))
        return;

    // Swap the values of the first two elements
    temp = (*stack_1)->stack_value;
    (*stack_1)->stack_value = (*stack_1)->next->stack_value;
    (*stack_1)->next->stack_value = temp;

	temp = (*stack_2)->stack_value;
    (*stack_2)->stack_value = (*stack_2)->next->stack_value;
    (*stack_2)->next->stack_value = temp;
	write(1,"ss\n", 3);
}