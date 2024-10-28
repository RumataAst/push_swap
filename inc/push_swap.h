/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akretov <akretov@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:29:03 by akretov           #+#    #+#             */
/*   Updated: 2024/04/16 19:13:35 by akretov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_alg_list
{
	int		num_a;
	int		num_b;
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		rr;
	int		rrr;
	int		total;
}	t_alg_list;

typedef struct s_list
{
	int				value;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

//stack_init
t_list	*create_node(char *value);
void	ft_connect_2_nodes(t_list *first, t_list *second);
void	ft_connect_plus_one(t_list *stack, t_list *new_node);
t_list	*ft_process(char **array);

// utils
void	ft_error_free(char **array);
void	ft_error(int i);
int		ft_atol(const char *str);
void	free_array(char **array);
int		ft_st_size(t_list *stack);
void	ft_st_clear(t_list **lst);

// alg_utils_0
int		ft_is_sorted(t_list *stack);
int		ft_st_min(t_list *lst);
int		ft_st_max(t_list *lst);
void	alg_list_init(t_alg_list *oper);
void	alg_list_cpy(t_alg_list *dest, const t_alg_list *src);

// alg_utils_1
int		close_l_num(t_list *stack, int desired_num);
int		close_h_num(t_list *stck, int desired_num);
void	ra_rb_is_lowest(t_alg_list *possblts, int ra_rb_oper);
void	rra_rrb_is_lowest(t_alg_list *possblts, int rra_rrb_oper);

// operations
void	ft_ra(t_list **stack);
void	ft_rb(t_list **stack);
void	ft_sa(t_list **stack);
void	ft_sb(t_list **stack);
void	ft_ss(t_list **stack_1, t_list **stack_2);
void	ft_rr(t_list **stack_1, t_list **stack_2);
void	ft_rra(t_list **stack);
void	ft_rrb(t_list **stack);
void	ft_rrr(t_list **stack_1, t_list **stack_2);
void	ft_pa_last(t_list **stck_b, t_list **stck_a, int *num_b, int *num_a);
void	ft_push(t_list **stack_1, t_list **stack_2, int *num_1, int *num_2);
void	ft_pa(t_list **stack_b, t_list **stack_a, int *num_b, int *num_a);
void	ft_pb(t_list **stack_a, t_list **stack_b, int *num_a, int *num_b);

// mini_sort
void	sort_three_nums(t_list **stack);

// han_errors
int		ft_check_unique(char **array);
int		ft_check_errors(char **array);
char	**get_values_from_argv(int ac, char **av);
char	**ft_check_ac(int ac, char **av);

// turk_alg_0
void	ft_algorithm(t_list **stack_a, t_list **stack_b);

//turk_alg_1
int		rx_operations(t_alg_list *possibilities);
void	numof_r_rr_moves(t_list *stck, int num_to_move, int *rx, int *rrx);
void	pick_lowest(t_alg_list *possblts);
void	get_numof_opers(t_alg_list	*oper, t_list *stck_a, t_list *stck_b);

//turk_alg_2
void	do_operations(t_alg_list *best_ch, t_list **stck_a, t_list **stck_b);

#endif