/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:36 by akretov           #+#    #+#             */
/*   Updated: 2024/02/08 19:15:34 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//CHANGEEE !!!

#include "push_swap.h"

t_list *ft_transform_to_stack(char **split_values)
{
    t_list *stack_a = NULL; // Initialize stack_a to NULL
    t_list *current = NULL; // Initialize a pointer to the current node

    int i = 0;

    while (split_values[i])
    {
        t_list *new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
            exit(1);
		
        new_node->stack_value = ft_atoi(split_values[i]);
        new_node->next = NULL;
        new_node->previous = NULL;

        // If it's the first node, set stack_a to the new node
        if (!stack_a)
        {
            stack_a = new_node;
            current = stack_a;
        }
        else
        {
            current->next = new_node;
            new_node->previous = current;
            current = new_node; // Update the current node to the new one
        }

        i++;
    }

    if (stack_a)
    {
        stack_a->previous = current; // Linking the first node's previous pointer to the last node
        current->next = stack_a; 	 // Linking the last node's next pointer to the first node
    }
    return (stack_a);
}
