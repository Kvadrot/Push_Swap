/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:57:32 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 13:18:41 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//	BASIC PUSH_SWAP COMMANDS
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// TODO: ft_rotate_stack
//---------------------------------------------------------------//
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
//---------------------------------------------------------------//
void	ft_rotate_stack(t_nd **origin_list, char *print_status)
{
	t_nd	*temp_head;

	temp_head = *origin_list;
	*origin_list = (*origin_list)->next;
	(*origin_list)->prev = NULL;
	temp_head->next = NULL;
	while ((*origin_list)->next)
	{
		origin_list = &((*origin_list)->next);
	}
	(*origin_list)->next = temp_head;
	temp_head->prev = *origin_list;
	ft_reset_t_nds_indx(origin_list);
	ft_printf("%s", print_status);
}

// TODO: ft_reverse_rotate_stack
//---------------------------------------------------------------//
// rra  Shift down all elements of stack a by 1.
// The last element becomes the first one.
//---------------------------------------------------------------//
void	ft_reverse_rotate_stack(t_nd **origin_list,
		char *print_status)
{
	t_nd	*temp_head;
	t_nd	*last_t_nd;

	if (*origin_list == NULL || (*origin_list)->next == NULL)
		return ;
	temp_head = *origin_list;
	last_t_nd = *origin_list;
	while (last_t_nd->next)
		last_t_nd = last_t_nd->next;
	last_t_nd->prev->next = NULL;
	last_t_nd->prev = NULL;
	last_t_nd->next = temp_head;
	temp_head->prev = last_t_nd;
	*origin_list = last_t_nd;
	ft_reset_t_nds_indx(origin_list);
	ft_printf("%s", print_status);
}

// TODO: ft_push_b
//---------------------------------------------------------------//
// pb (push b): Take the first element at the top of a and put it
// at the top of b.
// Do nothing if a is empty.
//---------------------------------------------------------------//
void	ft_push(t_nd **from_list, t_nd **to_list,
		char *print_status)
{
	t_nd	*temp_head;

	temp_head = *from_list;
	*from_list = (*from_list)->next;
	if (*from_list)
		(*from_list)->prev = NULL;
	temp_head->next = *to_list;
	if (*to_list)
		(*to_list)->prev = temp_head;
	*to_list = temp_head;
	temp_head->prev = NULL;
	ft_reset_t_nds_indx(from_list);
	ft_reset_t_nds_indx(to_list);
	ft_printf(print_status);
}

void	ft_swap(t_nd **origin_list, char *print_status)
{
	t_nd	*first;
	t_nd	*second;

	first = *origin_list;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*origin_list = second;
	ft_reset_t_nds_indx(origin_list);
	ft_printf("%s", print_status);
}
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||