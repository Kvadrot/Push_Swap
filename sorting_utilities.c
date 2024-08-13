/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:21:11 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 17:25:00 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_is_sorted
//---------------------------------------------------------------//
// Checks up the list is it sorted already
// If list is sorted - returns status code: 200
//---------------------------------------------------------------//
int	ft_is_sorted(t_nd **origin_list, bool ascending)
{
	t_nd	*temp_t_nd;

	temp_t_nd = *origin_list;
	if (ascending == true)
	{
		while (temp_t_nd->next)
		{
			if (temp_t_nd->number > temp_t_nd->next->number)
				return (-404);
			temp_t_nd = temp_t_nd->next;
		}
		return (200);
	}
	else
	{
		while (temp_t_nd->next)
		{
			if (temp_t_nd->number < temp_t_nd->next->number)
				return (-404);
			temp_t_nd = temp_t_nd->next;
		}
		return (200);
	}
}

// TODO: count_to_make_top
//---------------------------------------------------------------//
// coutns how many moves (RA, RRA) needs t_nd in searcher stack
//  depends on index
// Returns:
// 1) Positive number - represents the particular amount of RA or
//  RB CMD to move t_nd to the top
// 2) Negative number - represents the particular amount of RRA or
// RRB CMD to move t_nd to the top
// 3) 0 if t_nd is already on the top
//---------------------------------------------------------------//
int	count_to_make_top(t_nd **origin_list, t_nd *for_t_nd)
{
	int	mediana;
	int	t_nd_ind;
	int	list_len;

	if (*origin_list)
		list_len = ft_list_length(*origin_list);
	else
		list_len = 0;
	if (for_t_nd)
		t_nd_ind = for_t_nd->list_indx;
	else
		t_nd_ind = 0;
	mediana = list_len / 2;
	if (t_nd_ind == 0)
		return (0);
	else if (t_nd_ind <= mediana)
		return (t_nd_ind);
	else
		return (-(list_len - t_nd_ind));
}

// ft_find_cheapest_t_nd
//---------------------------------------------------------------//
// looks through the entire list for the lowest price for shifting
// RETURNS:
// The cheapest t_nd due to shifting_cost
//---------------------------------------------------------------//
t_nd	*ft_find_cheapest_t_nd(t_nd **origin)
{
	t_nd	*temp_list;
	t_nd	*cheapest_list;

	temp_list = *origin;
	cheapest_list = temp_list;
	while (temp_list)
	{
		if (temp_list->shifiting_cost < cheapest_list->shifiting_cost)
			cheapest_list = temp_list;
		temp_list = temp_list->next;
	}
	return (cheapest_list);
}

// ft_new_target_is_closer
//---------------------------------------------------------------//
// compares given t_nd.target.num with new_target.num
// Returns:
// -true if new_target.num > t_nd.target.num
// -false if new_target.num > t_nd.target.num
//---------------------------------------------------------------//
bool	ft_new_target_is_closer(t_nd *searcher, int new_target)
{
	long long int	searcher_val;
	long long int	current_target_val;
	long long int	new_target_val;

	searcher_val = searcher->number;
	current_target_val = searcher->target->number;
	new_target_val = new_target;
	if (current_target_val > searcher_val)
		return (true);
	if (ft_long_long_abs(searcher_val
			- new_target_val) < ft_long_long_abs(searcher_val
			- current_target_val))
		return (true);
	else
		return (false);
}
