/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:07:47 by akretov           #+#    #+#             */
/*   Updated: 2024/04/05 19:15:56 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// going through the stack
void print_stack(t_list* stack)
{
	t_list *current = stack;
	while (current != NULL) 
	{
		printf("%d \n", current->stack_value);
		current = current->next;
		if (current == stack)
			break;
	}
}

char **get_values_from_argv(int argc, char **argv)
{
    int i;

	i = 1;
	char **split_args = (char **)malloc(sizeof(char *) * argc);
    if (!split_args)
        return NULL;
    while (i < argc)
    {
        split_args[i - 1] = ft_strdup(argv[i]);
        if (!split_args[i - 1])
        {
            free_array(split_args, i - 1);
            return NULL;
        }
        i++;
    }
	split_args[i] = "\0";
    return (split_args);
}

int	main(int ac, char **av)
{
	t_list *stack_a = NULL;
	char	**split_values;

	// Transform from argc to array
	if (ac <= 1)
	{
		printf("Error, add values for stack a");
		return (1);
	}
	// numbers are in 1 argument separated by space
	else if (ac == 2)
		split_values = ft_split(av[1], ' ');
	// numbers are in separate arguments
	else
		split_values = get_values_from_argv(ac, av);

	// check input in han_errors
	// only unique numbers
	if (ft_check_errors(split_values) == 1)
	{
		// free_array(split_values, ac);
		return (1);
	}
	
	// transform from array to stack
	stack_a = ft_transform_to_stack(split_values);
	free(split_values);
	
	//Logic and algorithm 
	if (check(stack_a) == 1)
		printf("Correct from lowest to highest\n");
	else 
		printf("Incorrect, sorting is needed\n");
	// max_alg(stack_a);

	//Just to check the STACK
	// printf("There are %i numbers in stack A\n", numbers_in_stack(stack_a));
	// printf("Stack is \n");
	// print_stack(stack_a);


	//Checking operations
	// ra(&stack_a);
	t_list *stack_b = NULL;
	int int_a = numbers_in_stack(stack_a);
	int int_b = 0;
	pa(&stack_a, &stack_b, &int_a, &int_b);
	printf("\nint a = %i\n", int_a);
	printf("\nint b = %i\n", int_b);

	printf("\nNumbers in stack a\n");
	print_stack(stack_a);
	printf("\nNumbers in stack b\n");
	print_stack(stack_b);

	printf("\n");	
	pa(&stack_a, &stack_b, &int_a, &int_b);
	printf("\nint a = %i\n", int_a);
	printf("\nint b = %i\n", int_b);

	printf("\nNumbers in stack a\n");
	print_stack(stack_a);
	printf("\nNumbers in stack b\n");
	print_stack(stack_b);
	
	printf("\n");	
	rr(&stack_a, &stack_b);
	printf("\nNumbers in stack a\n");
	print_stack(stack_a);
	printf("\nNumbers in stack b\n");
	print_stack(stack_b);
	// free_array(split_values, ac);
	// push_swap(stack_a, stack_b);
	return (0);
}