/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_both.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:17:01 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 13:19:10 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rotate_both
// RR
//---------------------------------------------------------------//
// ra (rotate a): Shift up all elements of stack A & stack B by 1.
// The first element becomes the last one.
//---------------------------------------------------------------//
void	ft_rotate_both(t_nd **origin_list_a,
		t_nd **origin_list_b, char *print_status)
{
	ft_rotate_stack(origin_list_a, "");
	ft_rotate_stack(origin_list_b, "");
	ft_reset_t_nds_indx(origin_list_a);
	ft_reset_t_nds_indx(origin_list_b);
	ft_printf("%s", print_status);
}

// reverse_rotate_both
// RRR
//---------------------------------------------------------------//
// rra  Shift down all elements of stack A & stack B by 1.
// The last element becomes the first one.
//---------------------------------------------------------------//
void	ft_reverse_rotate_both(t_nd **origin_list_a,
		t_nd **origin_list_b, char *print_status)
{
	ft_reverse_rotate_stack(origin_list_a, "");
	ft_reverse_rotate_stack(origin_list_b, "");
	ft_reset_t_nds_indx(origin_list_a);
	ft_reset_t_nds_indx(origin_list_b);
	ft_printf("%s", print_status);
}
