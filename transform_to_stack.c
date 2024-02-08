/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:02:36 by akretov           #+#    #+#             */
/*   Updated: 2024/02/05 18:30:56 by akretov          ###   ########.fr       */
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
        // Create a new node
        t_list *new_node = (t_list *)malloc(sizeof(t_list));
        if (!new_node)
        {
            // Handle memory allocation error
            perror("Error allocating memory for a new node");
            exit(EXIT_FAILURE);
        }

        new_node->stack_value = ft_atoi(split_values[i]);
        new_node->next = NULL;

        // If it's the first node, set stack_a to the new node
        if (!stack_a)
        {
            stack_a = new_node;
            current = stack_a;
        }
        else
        {
            // If it's not the first node, link it to the current node
            current->next = new_node;
            current = new_node; // Update the current node to the new one
        }

        i++;
    }

    return (stack_a);
}