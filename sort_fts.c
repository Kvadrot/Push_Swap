/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:20:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 13:13:51 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_reset_targets
//---------------------------------------------------------------//
// looks for target t_nd for searcher_stack in target_src_stack
//
//---------------------------------------------------------------//
void	ft_reset_targets(t_nd **searcher_stack, t_nd **target_src_stack)
{
	t_nd	*temp_searcher;
	t_nd	*temp_src;

	temp_searcher = *searcher_stack;
	while (temp_searcher)
	{
		temp_src = *target_src_stack;
		temp_searcher->target = temp_src;
		while (temp_src)
		{
			if (temp_searcher->target->number < temp_src->number)
				temp_searcher->target = temp_src;
			temp_src = temp_src->next;
		}
		temp_src = *target_src_stack;
		while (temp_src)
		{
			if ((temp_searcher->number > temp_src->number)
				&& ft_new_target_is_closer(temp_searcher,
					temp_src->number) == true)
				temp_searcher->target = temp_src;
			temp_src = temp_src->next;
		}
		temp_searcher = temp_searcher->next;
	}
}

// ft_reset_costs
//---------------------------------------------------------------------//
// counts and sets for each searcher_stack t_nd how many moves does
// each stack need to be able to connect searcher_stack with target
// t_nd (both t_nds has to be on the top of their stack)
// HOW it WORKS:
// 1) coutns how many moves (RA, RRA) needs t_nd in searcher stack
// 2) counts how many moves (RA, RRA) needs t_nd in src stack
// 3) checks if there is a match during feature shifting t_nd commands
// to the top of stack, if so, we can reduce num of executing commands
// by using RR or RRR.
//--------------------------------------------------------------------//
void	ft_reset_costs(t_nd **searcher_list, t_nd **src_list)
{
	int		result;
	int		searcher_cmds;
	int		src_cmds;
	t_nd	*temp_searcher;

	temp_searcher = *searcher_list;
	while (temp_searcher)
	{
		searcher_cmds = count_to_make_top(searcher_list, temp_searcher);
		src_cmds = count_to_make_top(src_list, temp_searcher->target);
		if (src_cmds > 0 && searcher_cmds > 0 && (searcher_cmds > src_cmds
				|| searcher_cmds == src_cmds))
			result = searcher_cmds;
		else if (src_cmds > 0 && searcher_cmds > 0 && searcher_cmds < src_cmds)
			result = src_cmds;
		else if (src_cmds < 0 && searcher_cmds < 0 && (searcher_cmds < src_cmds
				|| searcher_cmds == src_cmds))
			result = ft_abs(searcher_cmds);
		else if (src_cmds < 0 && searcher_cmds < 0 && searcher_cmds > src_cmds)
			result = ft_abs(src_cmds);
		else
			result = ft_abs(src_cmds) + ft_abs(searcher_cmds);
		temp_searcher->shifiting_cost = result;
		temp_searcher = temp_searcher->next;
	}
}

// ft_sort_with_turk
//-----------------------------------------------------------------//
// Sorting algotrythm
// 1) pushes the two first elements from A -> B
// while (stack_a.t_nds.count != 3) {
// 2) ft_reset_targets() - Resets targets (targets - t_nds in stack_B) for t_nds
// in Stack A.
// 2.1) closest_t_nd() - Target is number in stack_B[i]
// stack_A[i] > stack_B[i] where stack_A[i] - stack_B[i] is closer to 1
// the number from stack_A might be upper the target
// 2.2) If number in stack_A is less then any of numbers in Stack_B
// then number just goes to the top of the Stack_B
// 3) ft_cost_reset() - resets the costs for each t_nd, according to targets
// 4) executes the instructions counted by cost_reset();
// 4.1) push Stack_A -> Stack_B
// }
// 5) if stack)_A is not sorted - sort it.
// while stack_B.t_nds != NULL {
// 6) ft_reset_targets() resets targets for t_nds in stack_B.
// 6.1) target is number in stack_A[i]
// stack_B[i] < stack_A[i] where stack_A[i] - stack_B[i] is closer to 1
// the number from stack_B might be upper the target
// 7) ft_cost_reset() resets the costs for each t_nd, according to targets
// 8) executes the instructions counted by cost_reset();
// 8.1) pushes the t_nd to the stack_A
// }
// 9) as soon as stack_B is empty, does RA or RRA until the stack is sorted.
void	ft_sort_with_turk(t_nd **origin_list_a, t_nd **origin_list_b)
{
	ft_push(origin_list_a, origin_list_b, "pb\n");
	ft_push(origin_list_a, origin_list_b, "pb\n");
	while (ft_list_length(*origin_list_a))
	{
		ft_reset_targets(origin_list_a, origin_list_b);
		ft_reset_costs(origin_list_a, origin_list_b);
		ft_shift_cheapest(origin_list_a, origin_list_b);
		ft_push(origin_list_a, origin_list_b, "pb\n");
	}
	while (ft_is_sorted(origin_list_b, false) != 200)
		ft_shift_t_nd_to_top(ft_find_max(origin_list_b), origin_list_b, 'b');
	while (ft_list_length(*origin_list_b))
		ft_push(origin_list_b, origin_list_a, "pa\n");
}
