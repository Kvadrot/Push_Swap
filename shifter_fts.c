/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifter_fts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:10:59 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 13:08:47 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_shift_t_nd_to_top
//---------------------------------------------------------------//
// depending on indx of the element takes descision which command
// whould take less steps to shift the t_nd on the top of the stack
// choose between the RA and RRA
//---------------------------------------------------------------//
void	ft_shift_t_nd_to_top(t_nd *t_nd_sh, t_nd **list_sh, char stackname)
{
	int		mediana;
	char	*print_status;

	mediana = ft_list_length(*list_sh) / 2;
	while (t_nd_sh->prev)
	{
		if (mediana >= t_nd_sh->list_indx)
		{
			if (stackname == 'a')
				print_status = "ra\n";
			else
				print_status = "rb\n";
			ft_rotate_stack(list_sh, print_status);
		}
		else
		{
			if (stackname == 'a')
				print_status = "rra\n";
			else
				print_status = "rrb\n";
			ft_reverse_rotate_stack(list_sh, print_status);
		}
	}
}

void	shift_both(t_nd *t_nd_a, t_nd **list_a, t_nd *t_nd_b, t_nd **list_b)
{
	int		searcher_commands;
	int		src_commands;
	t_nd	*cheapest_t_nd;

	cheapest_t_nd = ft_find_cheapest_t_nd(list_a);
	searcher_commands = count_to_make_top(list_a, cheapest_t_nd);
	while (t_nd_a->prev && t_nd_b->prev)
	{
		if (searcher_commands > 0)
		{
			ft_rotate_both(list_a, list_b, "rr\n");
		}
		else
		{
			ft_reverse_rotate_both(list_a, list_b, "rrr\n");
		}
	}
}

// ft_shift_cheapest
//---------------------------------------------------------------//
// looks through the entire list for the lowest price for shifting
// and shifts the t_nd until it reached the top.
// -Some times the sum of movements for both stack won't match with
// cost, that means that we have to apply RR or RRR
void	ft_shift_cheapest(t_nd **searcher_list, t_nd **src_list)
{
	t_nd	*cheapest_t_nd;
	int		searcher_commands;
	int		src_commands;

	cheapest_t_nd = ft_find_cheapest_t_nd(searcher_list);
	searcher_commands = count_to_make_top(searcher_list, cheapest_t_nd);
	src_commands = count_to_make_top(src_list, cheapest_t_nd->target);
	if (cheapest_t_nd->shifiting_cost == 0)
		return ;
	if ((searcher_commands > 0 && src_commands > 0) || (searcher_commands < 0
			&& src_commands < 0))
	{
		shift_both(cheapest_t_nd, searcher_list,
			cheapest_t_nd->target, src_list);
		ft_shift_t_nd_to_top(cheapest_t_nd, searcher_list, 'a');
		ft_shift_t_nd_to_top(cheapest_t_nd->target, src_list, 'b');
	}
	else
	{
		ft_shift_t_nd_to_top(cheapest_t_nd, searcher_list, 'a');
		ft_shift_t_nd_to_top(cheapest_t_nd->target, src_list, 'b');
	}
}
