/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigation_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 19:57:32 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/11 19:19:20 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//	BASIC PUSH_SWAP COMMANDS 
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

// ft_reset_nodes_indx
//---------------------------------------------------------------//
// resets the indexex for each node inside the node.
//---------------------------------------------------------------//
static void	ft_reset_nodes_indx(t_numbers_list **list_head)
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

//TODO: ft_rotate_stack
//---------------------------------------------------------------//
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
//---------------------------------------------------------------//
void	ft_rotate_stack(t_numbers_list **origin_list, char *print_status)
{
	t_numbers_list	*temp_head;

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
	ft_reset_nodes_indx(origin_list);
	ft_printf("%s", print_status);
}


//TODO: ft_reverse_rotate_stack
//---------------------------------------------------------------//
// rra  Shift down all elements of stack a by 1.
// The last element becomes the first one.
//---------------------------------------------------------------//
void	ft_reverse_rotate_stack(t_numbers_list **origin_list, char *print_status)
{
	t_numbers_list	*temp_head;
	t_numbers_list	*last_node;

	if (*origin_list == NULL || (*origin_list)->next == NULL)
		return;
	temp_head = *origin_list;
	last_node = *origin_list;
	while (last_node->next)
		last_node = last_node->next;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = temp_head;
	temp_head->prev = last_node;
	*origin_list = last_node;
	ft_reset_nodes_indx(origin_list);
	ft_printf("%s", print_status);
}


//TODO: ft_push_b
//---------------------------------------------------------------//
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
//---------------------------------------------------------------//
void	ft_push(t_numbers_list **from_list, t_numbers_list **to_list, char *print_status)
{
	t_numbers_list *temp_head;

	temp_head = *from_list;
		*from_list = (*from_list)->next;
	if (*from_list)
		(*from_list)->prev = NULL;
	temp_head->next = *to_list;
	if (*to_list)
		(*to_list)->prev = temp_head;
	*to_list = temp_head;
	temp_head->prev = NULL;
	ft_reset_nodes_indx(from_list);
	ft_reset_nodes_indx(to_list);
	ft_printf(print_status);
	global_var++;
}

// rotate_both
// RR
//---------------------------------------------------------------//
// ra (rotate a): Shift up all elements of stack A & stack B by 1.
// The first element becomes the last one.
//---------------------------------------------------------------//
void	ft_rotate_both(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b, char *print_status)
{
	ft_rotate_stack(origin_list_a, "");
	ft_rotate_stack(origin_list_b, "");
	ft_reset_nodes_indx(origin_list_a);
	ft_reset_nodes_indx(origin_list_b);
	ft_printf("%s", print_status);
}

// reverse_rotate_both
// RRR
//---------------------------------------------------------------//
// rra  Shift down all elements of stack A & stack B by 1.
// The last element becomes the first one.
//---------------------------------------------------------------//
void	ft_reverse_rotate_both(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b, char *print_status)
{
	ft_reverse_rotate_stack(origin_list_a, "");
	ft_reverse_rotate_stack(origin_list_b, "");
	ft_reset_nodes_indx(origin_list_a);
	ft_reset_nodes_indx(origin_list_b);
	ft_printf("%s", print_status);
}

void	ft_swap(t_numbers_list **origin_list, char *print_status)
{
	t_numbers_list	*first;
	t_numbers_list	*second;

	first = *origin_list;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*origin_list = second;
	ft_reset_nodes_indx(origin_list);
	ft_printf("%s", print_status);
}
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||