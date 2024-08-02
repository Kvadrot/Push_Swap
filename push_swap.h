/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:16 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/02 19:49:31 by itykhono         ###   ########.fr       */
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
	int				number;
	struct t_numbers_list	*next;
	struct t_numbers_list	*prev;
}	t_numbers_list;

// Validation_fts
bool	ft_is_valid_duplicates(int *numbers, int numbers_amount);
bool	ft_is_valid_limts(char **args);
bool	ft_is_valid_symbols(char **args);
int		*ft_validate_and_convert(char **arguments, int *processed_size);


// Basic_utilities
void	ft_clean_up_list(t_numbers_list *list);
int		ft_get_size_of_super_arr(char **super_arr);
char	**ft_copy_complex_arr(int argc, char **arr_of_arr);


// Navlist_commands
void	ft_push(t_numbers_list **from_list, t_numbers_list **to_list);
void	ft_rotate_stack(t_numbers_list **origin_list);
void	ft_reverse_rotate_stack(t_numbers_list **origin_list);


// Sort_fts
void	ft_sort_list(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b);

//Debug Fucntions
void	ft_debug_num_printer(t_numbers_list *list, char *separator_text);


#endif