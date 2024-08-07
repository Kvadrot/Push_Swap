/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:20:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/07 22:23:02 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int global_var = 0;
// ft_is_sorted
//---------------------------------------------------------------//
// Checks up the list is it sorted already
// If list is sorted - returns status code: 200
//---------------------------------------------------------------//
int	ft_is_sorted(t_numbers_list **origin_list)
{
	t_numbers_list	*temp_node;

	temp_node = *origin_list;
	while(temp_node->next)
	{
		if (temp_node->number > temp_node->next->number)
			return (-404);
		temp_node = temp_node->next;
	}
	return (200);
}

//TODO int ft_find_smallest_node()
//---------------------------------------------------------------//
// looks for the smallest node (the smallest num) in list
// returns node with smallest number
//---------------------------------------------------------------//
t_numbers_list	*ft_find_smallest_node(t_numbers_list *origin_list)
{
	t_numbers_list	*temp_node;
	t_numbers_list	*smallest_node;

	temp_node = origin_list;
	smallest_node = origin_list;
	while(temp_node->next)
	{
		if (smallest_node->number > temp_node->next->number)
			smallest_node = temp_node->next;
		temp_node = temp_node->next;
	}
	return (smallest_node);
}

// ft_shift_node_to_top
//---------------------------------------------------------------//
// depending on indx of the element takes descision which command
// whould take less steps to shift the node on the top of the stack
// choose between the RA and RRA
//---------------------------------------------------------------//
void	ft_shift_node_to_top(t_numbers_list *smallest_node, t_numbers_list **origin_list)
{
	int				mediana;

	mediana = ft_list_length(*origin_list) / 2;
	while(smallest_node->prev)
	{
		if ( mediana >= smallest_node->list_indx)
		{
			ft_rotate_stack(origin_list);
			ft_printf("ra\n");
			global_var++;
		} else {
			ft_reverse_rotate_stack(origin_list);
			ft_printf("rra\n");
			global_var++;
		}
		// ft_debug_num_printer(*origin_list, "shift result");
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
//---------------------------------------------------------------//
int	count_to_make_top(t_numbers_list **origin_list)
{
	int mediana;

	mediana = ft_list_length(*origin_list) / 2;
	
}

// TODO: ft_reset_costs
//---------------------------------------------------------------//
// counts and sets for each searcher_stack node how many moves does
// each stack need to be able to connect searcher_stack with target
// node (both nodes has to be on the top of their stack)
// HOW it WORKS:
// 1) coutns how many moves (RA, RRA) needs node in searcher stack
// 2) counts how many moves (RA, RRA) needs node in src stack
// 3) checks if there is a match during feature shifting node to
//  the top of stack, if so, we can reduce num of executing commands
//---------------------------------------------------------------//
void	ft_reset_costs(t_numbers_list **searcher_list, t_numbers_list **src_list)
{
	int result;

		while  (searcher_list)
		{
	    	int searcher_commands = count_to_make_top();
			int src_commands = count_to_make_top();
			if (src_commands > 0 && searcher_commands > 0)
			{
				result = ft_abs(src_commands - searcher_commands);
			} else if (src_commands < 0 && searcher_commands < 0)
			{
				result = ft_abs(ft_abs(src_commands) - ft_abs(searcher_commands));
			} else {
				result = ft_abs(src_commands) + ft_abs(searcher_commands);
			}
			(*searcher_list)->shifiting_cost = result;
			*searcher_list = (*searcher_list)->next;
		}
}

 //TODO: ft_sort_with_turk
//---------------------------------------------------------------//
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
	ft_push(origin_list_a, origin_list_b);
	ft_push(origin_list_a, origin_list_b);

	while (ft_list_length(*origin_list_a))
	{
		// ||||||||||||| TEST |||||||||
		// ft_reset_targets(origin_list_a, origin_list_b);
		// ft_debug_num_printer((*origin_list_a), "start_targeting_step");
		// ft_push(origin_list_a, origin_list_b);
		// ft_debug_num_printer((*origin_list_b), "end_targeting_step");
	// 	// ||||||||||||||||||||||||||||||

		ft_reset_targets(origin_list_a, origin_list_b);
		ft_debug_num_printer((*origin_list_a), "end_targeting_step");
		ft_push(origin_list_a, origin_list_b);

		ft_reset_costs(origin_list_a, origin_list_b);

		//execute commands;
	}
}

 //TODO: ft_sort_list
//---------------------------------------------------------------//
// Main sorting function
// Sorting algotrythm 
// 1) looks for the smallest num on the A_stack
// 1.2) depending on index of the node makes descision which
// navigation command (RA, RRA) takes less times to move
// the number on the top of the A_stack.
// 2) push the smallest num on the B stack
// 3) Each time it brings the node on the top of the A_stack
// it uses function ft_is_sorted to check up if the rest of stack
// is already sorted. 
// 4) when it is only one element on the stack it pushes everything
// back on top of the A_stack
// 5) pushes all nodes from B_stack on top of the A_stack.
//---------------------------------------------------------------//
// void ft_sort_list(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b)
// {
// 	t_numbers_list	*smallest_node;
// 	t_numbers_list	*temp_node;
// 	int				smallest_node_indx;

//NAVIGATION TEST
	// if (*origin_list_a == NULL)
	// 	return (-300);
	// if ((*origin_list_a)->next == NULL)
	// 	return (200);
	// ft_rotate_stack(origin_list_a);
	// ft_debug_num_printer(*origin_list_a, "after first RA");
	// ft_push(origin_list_a, origin_list_b);
	// ft_debug_num_printer(*origin_list_a, "A Stack after push_b");
	// ft_push(origin_list_b, origin_list_a);
	// ft_debug_num_printer(*origin_list_a, "A Stack after push_a");
	// ft_reverse_rotate_stack(origin_list_a);
	// ft_debug_num_printer(*origin_list_a, "after RRA");

	// ft_is_sorted TEST
	// ft_printf("is_sorted for stack a = %d\n", ft_is_sorted(origin_list_a));

	// ft_find_smallest_node TEST
	// ft_printf("the smallest node is with indx: %d\n", ft_find_smallest_node(origin_list_a));
	
	// ft_find_smallest_node TEST
	// ft_printf("the smallest node is with indx: %d\n", ft_find_smallest_node(origin_list_a)->list_indx);

	// ft_reset_nodes_indx TEST
	// ft_push(origin_list_a, origin_list_b);
	// ft_reset_nodes_indx(origin_list_a);
	// ft_debug_num_printer(*origin_list_a, "stack A after push and indx reset");
	// ft_printf("is_sorted for stack a = %d\n", ft_is_sorted(origin_list_a));
//



//
// SORT by the smalllest aproach
	// temp_node = *origin_list_a;
	// while (ft_is_sorted(&temp_node) == -404)
	// {
	// 	smallest_node = ft_find_smallest_node(temp_node);
	// 	ft_shift_node_to_top(smallest_node, origin_list_a);
	// 	ft_push(origin_list_a, origin_list_b);
	// 	ft_printf("pb\n");
	// 	global_var++;
	// 	ft_reset_nodes_indx(origin_list_a);
	// 	temp_node = *origin_list_a;
	// }

	// while (*origin_list_b)
	// {
	// 	ft_push(origin_list_b, origin_list_a);
	// 	global_var++;;
	// 	ft_printf("pa\n");
	// }
	// ft_debug_num_printer(*origin_list_a, "test sort");
// }