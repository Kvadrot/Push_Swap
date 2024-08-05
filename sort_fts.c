/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:20:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/05 21:11:33 by itykhono         ###   ########.fr       */
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

// ft_reset_nodes_indx
//---------------------------------------------------------------//
// resets the indexex for each node inside the node.
//---------------------------------------------------------------//
void	ft_reset_nodes_indx(t_numbers_list **list_head)
{
	t_numbers_list	*temp_node;
	int				new_node_ind;

	if (!list_head)
		return ;
	new_node_ind = 0;
	temp_node = *list_head;
	while(temp_node)
	{
		temp_node->list_indx = new_node_ind;
		temp_node = temp_node->next;
		new_node_ind++;
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
void ft_sort_list(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b)
{
	t_numbers_list	*smallest_node;
	t_numbers_list	*temp_node;
	int				smallest_node_indx;

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

// main appproach
	temp_node = *origin_list_a;
	while (ft_is_sorted(&temp_node) == -404)
	{
		smallest_node = ft_find_smallest_node(temp_node);
		ft_shift_node_to_top(smallest_node, origin_list_a);
		ft_push(origin_list_a, origin_list_b);
		ft_printf("pb\n");
		global_var++;
		ft_reset_nodes_indx(origin_list_a);
		temp_node = *origin_list_a;
	}

	while (*origin_list_b)
	{
		ft_push(origin_list_b, origin_list_a);
		global_var++;;
		ft_printf("pa\n");
	}
	// ft_debug_num_printer(*origin_list_a, "test sort");
}