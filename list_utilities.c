/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:16:24 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 18:17:24 by itykhono         ###   ########.fr       */
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
void	ft_clean_up_list(t_nd *list)
{
	t_nd	*temp;
	t_nd	*next_node;

	temp = list;
	while (temp)
	{
		next_node = temp->next;
		free(temp);
		temp = next_node;
	}
}

// ft_list_length()
//---------------------------------------------------------------//
// returns amount of t_nds inside of given List
//---------------------------------------------------------------//
int	ft_list_length(t_nd *list)
{
	t_nd	*temp;
	int		length;

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

// ft_reset_t_nds_indx
//---------------------------------------------------------------//
// resets the indexex for each t_nd inside the t_nd.
//---------------------------------------------------------------//
void	ft_reset_t_nds_indx(t_nd **list_head)
{
	t_nd	*temp_t_nd;
	int		new_t_nd_ind;

	if (!list_head)
		return ;
	new_t_nd_ind = 0;
	temp_t_nd = *list_head;
	while (temp_t_nd)
	{
		temp_t_nd->list_indx = new_t_nd_ind;
		temp_t_nd = temp_t_nd->next;
		new_t_nd_ind++;
	}
}

// ft_find_max
//-----------------------------------------------------------------//
// looks through the entire list for the t_nd with the biggest value
//-----------------------------------------------------------------//
t_nd	*ft_find_max(t_nd **list)
{
	t_nd	*temp_t_nd;
	t_nd	*max_t_nd;

	temp_t_nd = *list;
	max_t_nd = temp_t_nd;
	while (temp_t_nd)
	{
		if (temp_t_nd->number > max_t_nd->number)
			max_t_nd = temp_t_nd;
		temp_t_nd = temp_t_nd->next;
	}
	return (max_t_nd);
}

// ft_find_min
//-----------------------------------------------------------------//
// looks through the entire list for the t_nd with the biggest value
//-----------------------------------------------------------------//
t_nd	*ft_find_min(t_nd **list)
{
	t_nd	*temp_t_nd;
	t_nd	*max_t_nd;

	temp_t_nd = *list;
	max_t_nd = temp_t_nd;
	while (temp_t_nd)
	{
		if (temp_t_nd->number < max_t_nd->number)
			max_t_nd = temp_t_nd;
		temp_t_nd = temp_t_nd->next;
	}
	return (max_t_nd);
}
