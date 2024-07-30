/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:06:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/30 18:52:08 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//TODO: ft_handle_error()
//---------------------------------------------------------------//
// In case of error, it must display "Error" 
// followed by a ’\n’ on the standard error.
//---------------------------------------------------------------//
void	ft_handle_error(int err_code)
{
	ft_printf("======= %d =======\n", err_code);
	ft_printf("Error\n");
}

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
		ft_printf("list.num = %d is free\n", list->number);
		temp = list->next;
		free(list);
		list = temp;
	}
}

// ft_init_linkedlist
//---------------------------------------------------------------//
//t_numbers_list
//---------------------------------------------------------------//
t_numbers_list	*ft_init_linkedlist(int *converted_numbers, int arr_size)
{
	t_numbers_list	*head_list;
	t_numbers_list	*temp_list;
	t_numbers_list	*resulting_list;
	int				i;

	if (!converted_numbers || arr_size <= 0)
		return (NULL);
	head_list = (t_numbers_list *)malloc(sizeof(t_numbers_list));
	if (!head_list)
		return (NULL);
	head_list->number = converted_numbers[0];
	head_list->prev = NULL;
	resulting_list = head_list;
	i = 1;
	while (i < arr_size)
	{
		temp_list = (t_numbers_list *)malloc(sizeof(t_numbers_list));
		if (!temp_list)
		{
			ft_clean_up_list(resulting_list);
			return (NULL);
		}
		temp_list->number = converted_numbers[i];
		temp_list->prev = head_list;
		temp_list->next = NULL;
		head_list->next = temp_list;
		head_list = temp_list;
		i++;
	}
	head_list->next = NULL;
	return (resulting_list); 
}

// ft_process_input
//---------------------------------------------------------------//
// func that validates input (splits if necessary) 
// all in all it might create numbers_linked_list
// it should return the code status 200:OK - 4**:KO
//---------------------------------------------------------------//
int	ft_process_input(int argc, char **argv, t_numbers_list **list_a, t_numbers_list **list_b)
{
	int				processed_size;
	int				*coonverted_arguments;
	char			**preprocessed_arguments;
	int				ind;

	if (argc == 2)
		preprocessed_arguments = ft_split(argv[1], ' ');
	else
		preprocessed_arguments = ft_copy_complex_arr(argc, argv);
	coonverted_arguments = ft_validate_and_convert(preprocessed_arguments, &processed_size);
	if (!coonverted_arguments)
	{
		ft_handle_error(500);
		return (500);
	}
	int i = 0;
	while (i < processed_size)
	{
		printf("successed convertion for: %d\n", coonverted_arguments[i]);
		i++;
	}
	*list_a = ft_init_linkedlist(coonverted_arguments, processed_size);
	ind = 0;
	while (preprocessed_arguments[ind] != NULL)
	{
		free(preprocessed_arguments[ind]);
		ind++;
	}
	ft_debug_num_printer(*list_a, "initial Stack");
	free(preprocessed_arguments);
	free(coonverted_arguments);
	if (!list_a)
		return (501);
	return (200);
}
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//	BASIC PUSH_SWAP COMMANDS 
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
//TODO: ft_rotate_stack
//---------------------------------------------------------------//
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
//---------------------------------------------------------------//
void	ft_rotate_stack(t_numbers_list **origin_list)
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
}

//TODO: ft_push_a
//---------------------------------------------------------------//
// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty
//---------------------------------------------------------------//
void	ft_push_a(t_numbers_list *list_a, t_numbers_list *list_b)
{
}

//TODO: ft_push_b
//---------------------------------------------------------------//
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
//---------------------------------------------------------------//
void	ft_push_b(t_numbers_list *list_a, t_numbers_list *list_b)
{
	t_numbers_list	*sorted_arr;

	// return (sorted_arr);
}
// ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||

//TODO: ft_sort_lists
//---------------------------------------------------------------//
// Main sorting function
// in case of error returns ERROR ID
//---------------------------------------------------------------//
int	ft_sort_list(t_numbers_list **origin_list_a, t_numbers_list **origin_list_b)
{
	ft_rotate_stack(origin_list_a);
	ft_debug_num_printer(*origin_list_a, "after first RA");
	return (200);
}

// main
//---------------------------------------------------------------//
// If no parameters are specified, the programm must
// not display anything and give the
// prompt back.
//---------------------------------------------------------------//
int main(int argc, char **argv)
{
	t_numbers_list	*list_a;
	t_numbers_list	*list_b;

	list_a = NULL;
	list_b = NULL;

	if (ft_process_input(argc, argv, &list_a, &list_b) < 0)
		return (1);
	ft_sort_list(&list_a, &list_b);

	ft_clean_up_list(list_a);
	ft_clean_up_list(list_b);
	return (0);
}
