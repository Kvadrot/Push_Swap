/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:20:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/02 21:01:13 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//TODO: ft_is_sorted
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

 //TODO: ft_sort_list
//---------------------------------------------------------------//
// Main sorting function
// Sorting algotrythm 
// 1) looks for the smallest num on the A_stack
// 2) depending on index of the node makes descision which
// navigation command (RA, RRA) takes less times to move
// the number on the top of the A_stack.
// 3) push the smallest num on the B stack
// 4) when it is only one element on the stack it pushes everything
// back onto the A_stack
// 5) Each time it brings the node on the top of the A_stack
// it uses function ft_is_sorted to check up if the rest of stack is
// already sorted.
// 6) pushes all nodes from B_stack on top of the A_stack.
//---------------------------------------------------------------//
void ft_sort_list(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b)
{
	t_numbers_list	*smallest_node;
	t_numbers_list	*start_a_node;

//TEST
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
//
	
	ft_printf("is_sorted for stack a = %d\n", ft_is_sorted(origin_list_a));
}