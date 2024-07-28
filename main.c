/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:06:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/28 18:41:31 by itykhono         ###   ########.fr       */
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

//TODO: ft_process_input
//---------------------------------------------------------------//
// func that validates input + restructurize it with split
// all in all it might create numbers_linked_list
// it should return the code status 200:OK - 4**:KO
//---------------------------------------------------------------//
int	ft_process_input(int argc, char **argv, t_numbers_list *list_a, t_numbers_list *list_b)
{
	int		processed_size;
	int		*coonverted_arguments;
	char	**preprocessed_arguments;
	int		ind;
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
		printf("successed number: %d\n", coonverted_arguments[i]);
		i++;
	}
	while (preprocessed_arguments[ind] != NULL)
	{
		free(preprocessed_arguments[ind]);
		ind++;
	}
	free(preprocessed_arguments);
	free(coonverted_arguments);
	return (200);
}

//TODO: main
//---------------------------------------------------------------//
// If no parameters are specified, the program must
// not display anything and give the
// prompt back.
//---------------------------------------------------------------//
int main(int argc, char **argv)
{
	t_numbers_list	*list_a;
	t_numbers_list	*list_b;

	list_a = (t_numbers_list *)malloc(sizeof(t_numbers_list));
	list_b = (t_numbers_list *)malloc(sizeof(t_numbers_list));
	if (!list_a)
		return (1);
	if (!list_b)
	{
		free(list_a);
		return (2);
	}
	ft_process_input(argc, argv, list_a, list_b);
	free(list_a);
	free(list_b);
	return (0);
}

