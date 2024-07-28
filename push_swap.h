/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:16 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/28 15:35:49 by itykhono         ###   ########.fr       */
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
	struct t_list	*next;
	struct t_list	*prev;
}	t_numbers_list;

int	ft_get_size_of_super_arr(char **super_arr);
char	**ft_copy_complex_arr(int argc, char **arr_of_arr);

#endif