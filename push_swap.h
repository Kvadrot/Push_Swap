/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:16 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/30 18:50:19 by itykhono         ###   ########.fr       */
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

int		ft_get_size_of_super_arr(char **super_arr);
bool	ft_is_valid_duplicates(int *numbers, int numbers_amount);
char	**ft_copy_complex_arr(int argc, char **arr_of_arr);
bool	ft_is_valid_limts(char **args);
bool	ft_is_valid_symbols(char **args);
int		*ft_validate_and_convert(char **arguments, int *processed_size);

//Debug Fucntions
void	ft_debug_num_printer(t_numbers_list *list, char *separator_text);




#endif