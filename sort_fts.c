/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:20:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/11 21:59:36 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int global_var = 0;
// ft_is_sorted
//---------------------------------------------------------------//
// Checks up the list is it sorted already
// If list is sorted - returns status code: 200
//---------------------------------------------------------------//
int	ft_is_sorted(t_numbers_list **origin_list, bool ascending)
{
	t_numbers_list	*temp_node;

	temp_node = *origin_list;
	if (ascending == true)
	{
		while(temp_node->next)
		{
			if (temp_node->number > temp_node->next->number)
				return (-404);
			temp_node = temp_node->next;
		}
		return (200);
	} else {
		while(temp_node->next)
		{
			if (temp_node->number < temp_node->next->number)
				return (-404);
			temp_node = temp_node->next;
		}
		return (200);
	}
}

// ft_shift_node_to_top
//---------------------------------------------------------------//
// depending on indx of the element takes descision which command
// whould take less steps to shift the node on the top of the stack
// choose between the RA and RRA
//---------------------------------------------------------------//
void	ft_shift_node_to_top(t_numbers_list *node_to_shift, t_numbers_list **origin_list, char stackname)
{
	int				mediana;
	char	*print_status;
	mediana = ft_list_length(*origin_list) / 2;
	while(node_to_shift->prev)
	{
		if ( mediana >= node_to_shift->list_indx)
		{
			if (stackname == 'a')
				print_status = "ra\n";
			else
				print_status = "rb\n";
			ft_rotate_stack(origin_list, print_status);
			global_var++;
		} else {
			if (stackname == 'a')
				print_status = "rra\n";
			else
				print_status = "rrb\n";
			ft_reverse_rotate_stack(origin_list, print_status);
			global_var++;
		}
	}
}

void	ft_shift_both_to_top(t_numbers_list *searcher_to_shift, t_numbers_list **searcher_origin, t_numbers_list *src_to_shift, t_numbers_list **src_origin, int shifting_type)
{
	while(searcher_to_shift->prev && src_to_shift->prev)
	{
		if ( shifting_type > 0)
		{
			ft_rotate_both(searcher_origin, src_origin, "rr\n");
			global_var++;
		} else {
			ft_reverse_rotate_both(searcher_origin, src_origin, "rrr\n");
			global_var++;
		}
	}
}


// ft_new_target_is_closer
//---------------------------------------------------------------//
// compares given node.target.num with new_target.num
// Returns:
// -true if new_target.num > node.target.num
// -false if new_target.num > node.target.num
//---------------------------------------------------------------//
static	bool ft_new_target_is_closer(t_numbers_list *searcher, int new_target)
{
	long long int searcher_val;
	long long int current_target_val;
	long long int new_target_val;

	searcher_val = searcher->number;
	current_target_val = searcher->target->number;
	new_target_val = new_target;
	
	if (current_target_val > searcher_val)
		return (true);

	if (ft_long_long_abs(searcher_val - new_target_val) < ft_long_long_abs(searcher_val - current_target_val))
		return (true);
	else
		return (false);
}

// ft_reset_targets
//---------------------------------------------------------------//
// looks for target node for searcher_stack in target_src_stack
//
//---------------------------------------------------------------//
void	ft_reset_targets(t_numbers_list **searcher_stack, t_numbers_list **target_src_stack)
{
	t_numbers_list	*temp_searcher;
	t_numbers_list	*temp_src;

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
				&& ft_new_target_is_closer(temp_searcher, temp_src->number) == true)
				{
					temp_searcher->target = temp_src;					
				}
			temp_src = temp_src->next;
		}
		temp_searcher = temp_searcher->next;
	}
}


// TODO: count_to_make_top
//---------------------------------------------------------------//
// coutns how many moves (RA, RRA) needs node in searcher stack
//  depends on index
// Returns:
// 1) Positive number - represents the particular amount of RA or
//  RB CMD to move node to the top
// 2) Negative number - represents the particular amount of RRA or
// RRB CMD to move node to the top
// 3) 0 if node is already on the top
//---------------------------------------------------------------//
int	count_to_make_top(t_numbers_list **origin_list, t_numbers_list *for_node)
{
	int mediana;
	int	node_ind;
	int list_len;

	// ft_printf("for_node: %d, indx: %d\n", for_node->number, for_node->list_indx);
	
	if (*origin_list)
		list_len = ft_list_length(*origin_list);
	else
		list_len = 0;
	if (for_node)
		node_ind = for_node->list_indx;
	else
		node_ind = 0;
	mediana = list_len / 2;
	if (node_ind == 0)
		return (0);
	else if (node_ind <= mediana)
		return (node_ind);
	else
		return (-(list_len - node_ind));
}

// ft_reset_costs
//---------------------------------------------------------------------//
// counts and sets for each searcher_stack node how many moves does
// each stack need to be able to connect searcher_stack with target
// node (both nodes has to be on the top of their stack)
// HOW it WORKS:
// 1) coutns how many moves (RA, RRA) needs node in searcher stack
// 2) counts how many moves (RA, RRA) needs node in src stack
// 3) checks if there is a match during feature shifting node commands
// to the top of stack, if so, we can reduce num of executing commands
// by using RR or RRR.
//--------------------------------------------------------------------//
void	ft_reset_costs(t_numbers_list **searcher_list, t_numbers_list **src_list)
{
	int result;
	int searcher_commands;
	int src_commands;
	t_numbers_list	*temp_searcher;

	temp_searcher = *searcher_list;
	while  (temp_searcher)
	{
		searcher_commands = count_to_make_top(searcher_list, temp_searcher);
		src_commands = count_to_make_top(src_list, temp_searcher->target);
		if (src_commands > 0 && searcher_commands > 0 && (searcher_commands > src_commands || searcher_commands == src_commands))
		{
			result = searcher_commands;
		} else if (src_commands > 0 && searcher_commands > 0 && searcher_commands < src_commands)
		{
			result = src_commands;
		} else if (src_commands < 0 && searcher_commands < 0 && (searcher_commands < src_commands || searcher_commands == src_commands))
		{
			result = ft_abs(searcher_commands);
		} else if (src_commands < 0 && searcher_commands < 0 && searcher_commands > src_commands)
		{
			result = ft_abs(src_commands);
		} else {
			result = ft_abs(src_commands) + ft_abs(searcher_commands);
		}
		temp_searcher->shifiting_cost = result;
		temp_searcher = temp_searcher->next;
	}
}
// ft_find_cheapest_node
//---------------------------------------------------------------//
// looks through the entire list for the lowest price for shifting
// RETURNS:
// The cheapest node due to shifting_cost
t_numbers_list *ft_find_cheapest_node(t_numbers_list **origin)
{
	t_numbers_list	*temp_list;
	t_numbers_list	*cheapest_list;

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

// ft_shift_cheapest
//---------------------------------------------------------------//
// looks through the entire list for the lowest price for shifting
// and shifts the node until it reached the top.
// -Some times the sum of movements for both stack won't match with
// cost, that means that we have to apply RR or RRR 
void	ft_shift_cheapest(t_numbers_list **searcher_list, t_numbers_list **src_list)
{
	t_numbers_list *cheapest_node;
	int searcher_commands;
	int src_commands;

	cheapest_node = ft_find_cheapest_node(searcher_list);
	searcher_commands = count_to_make_top(searcher_list, cheapest_node);
	src_commands = count_to_make_top(src_list, cheapest_node->target);
	if (cheapest_node->shifiting_cost == 0)
		return ;
	if ((searcher_commands > 0 && src_commands > 0) || (searcher_commands < 0 && src_commands < 0) )
	{
		ft_shift_both_to_top(cheapest_node, searcher_list, cheapest_node->target, src_list, searcher_commands);
		ft_shift_node_to_top(cheapest_node, searcher_list, 'a');
		ft_shift_node_to_top(cheapest_node->target, src_list, 'b');
	} else {
		ft_shift_node_to_top(cheapest_node, searcher_list, 'a');
		ft_shift_node_to_top(cheapest_node->target, src_list, 'b');
	}
}


// ft_find_max
//-----------------------------------------------------------------//
// looks through the entire list for the node with the biggest value
t_numbers_list *ft_find_max(t_numbers_list **list)
{
	t_numbers_list *temp_node;
	t_numbers_list *max_node;

	temp_node = *list;
	max_node = temp_node;
	while (temp_node)
	{
		if (temp_node->number > max_node->number)
			max_node = temp_node;
		temp_node = temp_node->next;
	}
	return (max_node);
}

// ft_find_min
//-----------------------------------------------------------------//
// looks through the entire list for the node with the biggest value
t_numbers_list *ft_find_min(t_numbers_list **list)
{
	t_numbers_list *temp_node;
	t_numbers_list *max_node;

	temp_node = *list;
	max_node = temp_node;
	while (temp_node)
	{
		if (temp_node->number < max_node->number)
			max_node = temp_node;
		temp_node = temp_node->next;
	}
	return (max_node);
}

 //TODO: ft_sort_with_turk
//-----------------------------------------------------------------//
// Sorting algotrythm 
// 1) pushes the two first elements from A -> B

// while (stack_a.nodes.count != 3) {
// 2) ft_reset_targets() - Resets targets (targets - nodes in stack_B) for nodes 
// in Stack A.
// 2.1) closest_node() - Target is number in stack_B[i] 
// stack_A[i] > stack_B[i] where stack_A[i] - stack_B[i] is closer to 1
// the number from stack_A might be upper the target
// 2.2) If number in stack_A is less then any of numbers in Stack_B
// then number just goes to the top of the Stack_B 
// 3) ft_cost_reset() - resets the costs for each node, according to targets 
// 4) executes the instructions counted by cost_reset();
// 4.1) push Stack_A -> Stack_B 
// }

// 5) if stack)_A is not sorted - sort it.

// while stack_B.nodes != NULL {
// 6) ft_reset_targets() resets targets for nodes in stack_B.
// 6.1) target is number in stack_A[i]
// stack_B[i] < stack_A[i] where stack_A[i] - stack_B[i] is closer to 1
// the number from stack_B might be upper the target
// 7) ft_cost_reset() resets the costs for each node, according to targets 
// 8) executes the instructions counted by cost_reset();
// 8.1) pushes the node to the stack_A
// }

// 9) as soon as stack_B is empty, does RA or RRA until the stack is sorted.

void ft_sort_with_turk(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b)
{
	ft_push(origin_list_a, origin_list_b, "pb\n");
	ft_push(origin_list_a, origin_list_b, "pb\n");

	// TEST
	while (ft_list_length(*origin_list_a))
	{
		ft_reset_targets(origin_list_a, origin_list_b);
		ft_reset_costs(origin_list_a, origin_list_b);
		ft_shift_cheapest(origin_list_a, origin_list_b);
		ft_push(origin_list_a, origin_list_b, "pb\n");
	}
	while (ft_is_sorted(origin_list_b, false) != 200)
		ft_shift_node_to_top(ft_find_max(origin_list_b), origin_list_b, 'b');
	while (ft_list_length(*origin_list_b))
		ft_push(origin_list_b, origin_list_a, "pa\n");
	// ft_debug_num_printer((*origin_list_a), "end_sorting_step");
}


// ft_sort_three
// sorts only if list contains 3 elements
//-----------------------------------------------------------------//
// 1) find min max values
// 2) if min.ind > max.ind => sa
// 2.1) check ft_is_sorted
// 3) ft_shift_to_top(min)
//-----------------------------------------------------------------//
void	ft_sort_three(t_numbers_list **origin_list_a)
{
	t_numbers_list	*max_node;
	t_numbers_list	*min_node;
	int				diff;

	max_node = ft_find_max(origin_list_a);
	min_node = ft_find_min(origin_list_a);
	diff = ft_abs(min_node->list_indx - max_node->list_indx);
	if (min_node->list_indx > max_node->list_indx && diff == 1)
	{
		ft_shift_node_to_top(min_node, origin_list_a, 'a');
	} else {
		ft_swap(origin_list_a, "sa\n");
		ft_shift_node_to_top(min_node, origin_list_a, 'a');
	}
}


void	ft_sort_five(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b)
{
	t_numbers_list	*min_node;
	int				diff;

	while (ft_list_length(*origin_list_a) > 3)
	{
		min_node = ft_find_min(origin_list_a);
		ft_shift_node_to_top(min_node, origin_list_a, 'a');		
		ft_push(origin_list_a, origin_list_b, "pb\n");
	}
	if ((*origin_list_b)->number < (*origin_list_b)->next->number)
		ft_swap(origin_list_b, "sb");
	ft_sort_three(origin_list_a);
	ft_push(origin_list_b, origin_list_a, "pa\n");
	ft_push(origin_list_b, origin_list_a, "pa\n");
	// ft_debug_num_printer((*origin_list_a), "end_sorting_step");

}