/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:16:24 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/12 14:26:03 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_clean_up_list
//---------------------------------------------------------------//
// Free up the linked list
// One by one from last to first
// Examlpe:
// 0 <- 10
//---------------------------------------------------------------//
void	ft_clean_up_list(t_numbers_list *list)
{
    t_numbers_list	*temp;

	while (list)
	{
		// ft_printf(" = %d is free\n", list->number);
		temp = list->next;
		free(list);
		list = temp;
	}
}

// ft_list_length()
//---------------------------------------------------------------//
// returns amount of nodes inside of given List
//---------------------------------------------------------------//
int	ft_list_length(t_numbers_list *list)
{
    t_numbers_list	*temp;
	int				length;

	if (!list)
		return (0);
	length = 1;
	temp = list;
	while (temp->next)
	{
		temp = temp->next;
		length++;
	}
	return (length);
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
	while (temp_node)
	{
		temp_node->list_indx = new_node_ind;
		temp_node = temp_node->next;
		new_node_ind++;
	}
}
