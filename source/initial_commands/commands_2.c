/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:29:09 by akretov           #+#    #+#             */
/*   Updated: 2024/04/07 16:06:19 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void push(t_list **stack_a, t_list **stack_b, int *numbs_in_a, int *numbs_in_b) 
{
    // Create a pointer to the node where we start in stack_a
    t_list *start_pointer = *stack_a;

    // Move stack_a to the next node
    *stack_a = (*stack_a)->next;

    // Update pointers in the previousious node
    if (start_pointer->previous != NULL) {
        start_pointer->previous->next = start_pointer->next;
    }

    // Update pointers in the next node
    if (start_pointer->next != NULL) {
        start_pointer->next->previous = start_pointer->previous;
    }

    // Update pointers in start_pointer
    start_pointer->previous = NULL;
    start_pointer->next = *stack_b;

    // If stack_b is not empty, update its previousious pointer
    if (*stack_b != NULL) {
        (*stack_b)->previous = start_pointer;
    }

    // Update stack_b to point to the new top node
    *stack_b = start_pointer;

    // Update the next pointer of the previousious node in stack_a
    if (*stack_a != NULL) {
        (*stack_a)->previous = NULL;
    }
    // Update counts
    (*numbs_in_a)--;
    (*numbs_in_b)++;
}

void pa(t_list **stack_a, t_list **stack_b, int *numbs_in_a, int *numbs_in_b) 
{
    // Call the push function to perform the push operation
    push(stack_a, stack_b, numbs_in_a, numbs_in_b);
    
    // Write "pa\n" to stdout
    write(1, "pa\n", 3);
}

void pb(t_list **stack_a, t_list **stack_b, int *numbs_in_a, int *numbs_in_b) 
{
    // Call the push function to perform the push operation
    push(stack_a, stack_b, numbs_in_a, numbs_in_b);
    
    // Write "pb\n" to stdout
    write(1, "pb\n", 3);
}