/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:20:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/02 17:44:51 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

 //TODO: ft_sort_lists
//---------------------------------------------------------------//
// Main sorting function
// in case of error returns ERROR ID
//---------------------------------------------------------------//
int	ft_sort_list(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b)
{
	t_numbers_list	*smallest_node;
	t_numbers_list	*start_a_node;

	if (*origin_list_a == NULL)
		return (-300);
	if ((*origin_list_a)->next == NULL)
		return (200);
	ft_rotate_stack(origin_list_a);
	ft_debug_num_printer(*origin_list_a, "after first RA");
	ft_push(origin_list_a, origin_list_b);
	ft_debug_num_printer(*origin_list_a, "A Stack after push_b");
	ft_push(origin_list_b, origin_list_a);
	ft_debug_num_printer(*origin_list_a, "A Stack after push_a");

	return (200);
}