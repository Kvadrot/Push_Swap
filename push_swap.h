/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:12:16 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/27 18:57:41 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <unistd.h>
# include <stdio.h>

typedef struct t_numbers_list {
	int				number;
	struct t_list	*next;
	struct t_list	*prev;
}	t_numbers_list;


#endif