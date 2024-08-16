/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:02:46 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/16 16:06:22 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_sort_three
// sorts only if list contains 3 elements
//-----------------------------------------------------------------//
// 1) find min max values
// 2) if min.ind > max.ind => sa
// 2.1) check ft_is_sorted
// 3) ft_shift_to_top(min)
//-----------------------------------------------------------------//
void	ft_sort_three(t_nd **origin_list_a)
{
	t_nd	*max_t_nd;
	t_nd	*min_t_nd;
	int		diff;

	diff = 0;
	max_t_nd = ft_find_max(origin_list_a);
	min_t_nd = ft_find_min(origin_list_a);
	diff = ft_abs(min_t_nd->list_indx - max_t_nd->list_indx);
	if (min_t_nd->list_indx > max_t_nd->list_indx && diff == 1)
	{
		ft_shift_t_nd_to_top(min_t_nd, origin_list_a, 'a');
	}
	else
	{
		ft_swap(origin_list_a, "sa\n");
		ft_shift_t_nd_to_top(min_t_nd, origin_list_a, 'a');
	}
}

void	ft_sort_five(t_nd **origin_list_a, t_nd **origin_list_b)
{
	t_nd	*min_t_nd;
	int		diff;

	diff = 0;
	min_t_nd = NULL;
	while (ft_list_length(*origin_list_a) > 3)
	{
		min_t_nd = ft_find_min(origin_list_a);
		ft_shift_t_nd_to_top(min_t_nd, origin_list_a, 'a');
		ft_push(origin_list_a, origin_list_b, "pb\n");
	}
	if ((*origin_list_b)->number < (*origin_list_b)->next->number)
		ft_swap(origin_list_b, "sb");
	if (ft_is_sorted(origin_list_a, true) == false)
		ft_sort_three(origin_list_a);
	ft_push(origin_list_b, origin_list_a, "pa\n");
	ft_push(origin_list_b, origin_list_a, "pa\n");
}
