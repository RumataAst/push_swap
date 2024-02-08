/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:20:19 by akretov           #+#    #+#             */
/*   Updated: 2024/02/05 18:20:56 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include "libft/libft.h"

// struct definition 
typedef struct s_list
{
	int				stack_value;
	// struct s_list	*previous;
	struct s_list	*next;
}	t_list;

// split definition
int	ft_isdigit(int c);
size_t	ft_strlen(const char *str);
char	**free_array(char **ptr, int i);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int	ft_check_errors(char **split_values);
char **get_values_from_argv(int argc, char **argv);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_check_errors(char **split_values);
int ft_check_unique(char **split_values);
void	*ft_calloc(size_t nmemb, size_t size);
int	ft_atoi(const char *str);
t_list *ft_transform_to_stack(char **split_values);

// DELETE
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));

#endif