/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:03:44 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 13:36:35 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./lib_ft/libft.h"
# include "./lib_ft_printf/ft_printf.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>

typedef struct t_nd
{
	struct t_nd	*next;
	struct t_nd	*prev;
	struct t_nd	*target;
	int			number;
	int			list_indx;
	int			shifiting_cost;
	int			reach_target_cost;
}				t_nd;

// Validation_fts
bool			ft_is_valid_duplicates(int *numbers, int numbers_amount);
bool			ft_is_valid_limts(char **args);
bool			ft_is_valid_symbols(char **args);
int				*ft_validate_and_convert(char **arguments, int *processed_size);

// List_utilities
t_nd			*ft_find_min(t_nd **list);
t_nd			*ft_find_max(t_nd **list);
int				ft_list_length(t_nd *list);
void			ft_clean_up_list(t_nd *list);
void			ft_reset_t_nds_indx(t_nd **list_head);

// Array_utilities
void			ft_free_complex_array(void **array);
int				ft_len_super_arr(char **super_arr);
char			**ft_copy_complex_arr(int argc, char **arr_of_arr);

// Basic_utilities
int				ft_abs(int n);
int				ft_put_error(int err_status, char *err_text);
long long int	ft_long_long_abs(long long int n);

// Navlist_commands
void			ft_swap(t_nd **origin_list, char *print_status);
void			ft_push(t_nd **from_list, t_nd **to_list, char *print_status);
void			ft_rotate_stack(t_nd **origin_list, char *print_status);
void			ft_reverse_rotate_stack(t_nd **origin_list, char *print_status);
void			ft_rotate_both(t_nd **origin_list_a, t_nd **origin_list_b,
					char *print_status);
void			ft_reverse_rotate_both(t_nd **origin_list_a,
					t_nd **origin_list_b, char *print_status);

// Sort_small_list
void			ft_sort_three(t_nd **origin_list_a);
void			ft_sort_five(t_nd **origin_list_a, t_nd **origin_list_b);

// Sort_fts
void			ft_sort_with_turk(t_nd **origin_list_a, t_nd **origin_list_b);

// Sort_utilities
t_nd			*ft_find_cheapest_t_nd(t_nd **origin);
int				ft_is_sorted(t_nd **origin_list, bool ascending);
int				count_to_make_top(t_nd **origin_list, t_nd *for_t_nd);
bool			ft_new_target_is_closer(t_nd *searcher, int new_target);

// Shifter_fts

void			ft_shift_cheapest(t_nd **searcher_list, t_nd **src_list);
void			ft_shift_t_nd_to_top(t_nd *t_nd_to_shift, t_nd **origin_list,
					char stackname);
void			shift_both(t_nd *searcher_to_shift, t_nd **searcher_origin,
					t_nd *src_to_shift, t_nd **src_origin);

#endif
