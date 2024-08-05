/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:16 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/05 23:12:05 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "./lib_ft/libft.h"
# include "./lib_ft_printf/ft_printf.h"

typedef struct t_numbers_list {
	struct t_numbers_list	*next;
	struct t_numbers_list	*prev;
	struct t_numbers_list	*target;
	int						number;
	int						list_indx;
	int						reach_target_cost;
}	t_numbers_list;

extern int global_var;

// Validation_fts
bool	ft_is_valid_duplicates(int *numbers, int numbers_amount);
bool	ft_is_valid_limts(char **args);
bool	ft_is_valid_symbols(char **args);
int		*ft_validate_and_convert(char **arguments, int *processed_size);


// Basic_utilities
int		ft_list_length(t_numbers_list *list);
void	ft_clean_up_list(t_numbers_list *list);
int		ft_get_size_of_super_arr(char **super_arr);
char	**ft_copy_complex_arr(int argc, char **arr_of_arr);


// Navlist_commands
void	ft_push(t_numbers_list **from_list, t_numbers_list **to_list);
void	ft_rotate_stack(t_numbers_list **origin_list);
void	ft_reverse_rotate_stack(t_numbers_list **origin_list);
void	rotate_both(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b);
void	reverse_rotate_both(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b);


// Sort_fts
t_numbers_list	*ft_find_smallest_node(t_numbers_list *origin_list);
void ft_sort_with_turk(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b);
// void			ft_sort_list(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b);

//Debug Fucntions
void	ft_debug_num_printer(t_numbers_list *list, char *separator_text);



#endif

