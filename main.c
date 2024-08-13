/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:06:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 18:50:18 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_node_int(int *i, int *numbers, t_nd **head, t_nd **temp)
{
	(*temp)->number = numbers[*i];
	(*temp)->list_indx = *i;
	(*temp)->prev = *head;
	(*temp)->next = NULL;
	(*head)->next = *temp;
	*head = *temp;
	(*i)++;
}

// ft_init_linkedlist
//---------------------------------------------------------------//
//
//---------------------------------------------------------------//
t_nd	*ft_init_linkedlist(int *converted_numbers, int arr_size)
{
	t_nd	*head_list;
	t_nd	*temp_list;
	t_nd	*resulting_list;
	int		i;

	head_list = (t_nd *)malloc(sizeof(t_nd));
	if (!head_list)
		return (NULL);
	head_list->number = converted_numbers[0];
	head_list->prev = NULL;
	resulting_list = head_list;
	i = 1;
	while (i < arr_size)
	{
		temp_list = (t_nd *)malloc(sizeof(t_nd));
		if (!temp_list)
		{
			ft_clean_up_list(resulting_list);
			return (NULL);
		}
		ft_node_int(&i, converted_numbers, &head_list, &temp_list);
	}
	ft_reset_t_nds_indx(&resulting_list);
	head_list->next = NULL;
	return (resulting_list);
}

static int	ft_process_input_helper(char **raw_args, int *processed_size,
		t_nd **list_a)
{
	int	*converted_args;

	converted_args = ft_validate_and_convert(raw_args, processed_size);
	if (!converted_args)
	{
		ft_free_complex_array((void **)(raw_args));
		return (ft_put_error(-501, "Error\n"));
	}
	*list_a = ft_init_linkedlist(converted_args, *processed_size);
	ft_free_complex_array((void **)(raw_args));
	free(converted_args);
	if (!list_a)
		return (ft_put_error(-502, "Error\n"));
	return (200);
}

// ft_process_input
//---------------------------------------------------------------//
// func that validates input (splits if necessary)
// all in all it might create numbers_linked_list
// it should return:
// OK: amount of t_nds inside the List
// KO: -5**
//---------------------------------------------------------------//
static int	ft_process_input(int argc, char **argv, t_nd **list_a)
{
	int		processed_size;
	char	**raw_args;

	if (argc == 2)
		raw_args = ft_split(argv[1], ' ');
	else
		raw_args = ft_copy_complex_arr(argc, argv);
	if (!raw_args)
		return (ft_put_error(-501, "Error\n"));
	else if (ft_len_super_arr(raw_args) == 0)
	{
		ft_free_complex_array((void **)(raw_args));
		return (404);
	}
	return (ft_process_input_helper(raw_args, &processed_size, list_a));
}

// main
//---------------------------------------------------------------//
// If no parameters are specified, the programm must
// not display anything and give the
// prompt back.
//---------------------------------------------------------------//
int	main(int argc, char **argv)
{
	t_nd	*list_a;
	t_nd	*list_b;
	int		processed_status;

	list_a = NULL;
	list_b = NULL;
	processed_status = ft_process_input(argc, argv, &list_a);
	if (processed_status < 0)
		return (1);
	else if (processed_status == 404)
		return (0);
	else if (ft_is_sorted(&list_a, true) == 200)
	{
		ft_clean_up_list(list_a);
		return (0);
	}
	else if (ft_list_length(list_a) == 3)
		ft_sort_three(&list_a);
	else if (ft_list_length(list_a) == 5)
		ft_sort_five(&list_a, &list_b);
	else
		ft_sort_with_turk(&list_a, &list_b);
	ft_clean_up_list(list_a);
	ft_clean_up_list(list_b);
	return (0);
}
