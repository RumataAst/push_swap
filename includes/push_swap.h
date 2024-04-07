/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 18:06:46 by akretov           #+#    #+#             */
/*   Updated: 2024/04/05 17:25:13 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// libraries
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <ctype.h> 

// struct definition 
typedef struct s_list
{
	int				stack_value;
	struct s_list	*previous;
	struct s_list	*next;
}	t_list;

// utils (free array is not working)
char	**free_array(char **ptr, int i);
int		check(t_list* stack_a);
int		numbers_in_stack(t_list* stack);

// han_errors
int ft_check_unique(char **split_values);
int	ft_check_errors(char **split_values);

// initial_commands
void sa(t_list** stack);
void sb(t_list** stack);
void ss(t_list** stack_1, t_list**stack_2);
void ra(t_list** stack);
void rb(t_list** stack);
void rr(t_list** stack_1, t_list** stack_2);
void rra(t_list** stack);
void rrb(t_list** stack);
void rrr(t_list** stack_1, t_list** stack_2);
void push(t_list **stack_a, t_list **stack_b, int *numbs_in_a, int *numbs_in_b); 
void pa(t_list **stack_a, t_list **stack_b, int *numbs_in_a, int *numbs_in_b);
void pa(t_list **stack_a, t_list **stack_b, int *numbs_in_a, int *numbs_in_b);

//libft - REMOVE AFTER
int	ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(const char *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s);
// UPDATE SPLIT IN LIBFT!!
char	**ft_split(char const *s, char c);

//push_swap_main
void print_stack(t_list* stack);
char **get_values_from_argv(int argc, char **argv);

// transform_to_stack 
t_list *ft_transform_to_stack(char **split_values);

#endif