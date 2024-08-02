/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:06:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/02 21:55:16 by itykhono         ###   ########.fr       */
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

// ft_init_linkedlist
//---------------------------------------------------------------//
//
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
	head_list->list_indx = 0;
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
		temp_list->list_indx = i;
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
// it should return:
// OK: amount of nodes inside the List
// KO: -5**
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
		ft_handle_error(-500);
		return (-500);
	}
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// TEST PART
	int i = 0;
	while (i < processed_size)
	{
		printf("successed convertion for: %d\n", coonverted_arguments[i]);
		i++;
	}
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
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
		return (-501);
	return (ind);
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
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
// TEST PART
	// int a = ft_process_input(argc, argv, &list_a, &list_b);
	// int test = ft_list_length(list_a);
	// ft_printf("init func gives: %d nodes, ft_list_length gives: %d\n", a, test);
// |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	ft_sort_list(&list_a, &list_b);
	ft_clean_up_list(list_a);
	ft_clean_up_list(list_b);
	return (0);
}
