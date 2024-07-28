/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:06:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/28 15:44:36 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//TODO: ft_handle_error()
//---------------------------------------------------------------//
// In case of error, it must display "Error" 
// followed by a ’\n’ on the standard error.
//---------------------------------------------------------------//
void ft_handle_error(int err_code)
{
	ft_printf("======= %d =======\n", err_code);
	ft_printf("Error\n");
}

//TODO: ft_validate_symbols()
//---------------------------------------------------------------//
// func that validates input:
// input must be between INT_MAX INT_MIN
//---------------------------------------------------------------//
bool	ft_is_valid_limts(char **args)
{
	int	max_int;
	int	min_int;

	max_int = 2147483647;
	min_int = -2147483648;

	while (args)
	{

	}	
	return (true);
}

//TODO: ft_validate_symbols()
//---------------------------------------------------------------//
// func that validates input:
// ONLY 0123456789
//---------------------------------------------------------------//
bool	ft_is_valid_symbols(char **args)
{
	int	ind;
	int	sym_ind;

	ind = 0;
	sym_ind = 0;
	while (args[ind] != NULL)
	{
		if ((args[ind][sym_ind] == '-' || args[ind][sym_ind] == '+') && sym_ind == 0)
			sym_ind++;
		while (args[ind][sym_ind] != '\0')
		{
			if (ft_isdigit(args[ind][sym_ind]) == false)
				return (false);
			sym_ind++;
		}
		sym_ind = 0;
		ind++;
	}
	return (true);
}


//TODO: ft_validate()
//---------------------------------------------------------------//
// func that validates input:
// NO duplicates
// ONLY Numbers
// INT limits
// it should return the arr of Int or NULL
//---------------------------------------------------------------//
int	*ft_validate_and_convert(char **arguments)
{
	int	i;
	int	*result;

	i = 0;
	if (!arguments)
		return (NULL);
	if (ft_is_valid_symbols(arguments) == false)
		return (NULL);
	if (ft_is_valid_limts(arguments) == false)
		return (NULL);
	result = (int *)malloc(sizeof(int) * ft_get_size_of_super_arr(arguments));
	if (!result)
		return (NULL);

	while (arguments[i])
	{
		atoi(arguments[i]);
		i++;
	}
	return (result);
}

//TODO: ft_process_input
//---------------------------------------------------------------//
// func that validates input + restructurize it with split
// all in all it might create numbers_linked_list
// it should return the code status 200:OK - 4**:KO
//---------------------------------------------------------------//
int	ft_process_input(int argc, char **argv, t_numbers_list *list_a, t_numbers_list *list_b)
{
	int		*coonverted_arguments;
	char	**preprocessed_arguments;
	if (argc == 2)
		preprocessed_arguments = ft_split(argv[1], ' ');
	else
		preprocessed_arguments = ft_copy_complex_arr(argc, argv);

	coonverted_arguments = ft_validate_and_convert(preprocessed_arguments);

	if (!coonverted_arguments)
	{
		ft_handle_error(500);
		return (500);
	}
	
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
	
	return (0);
}

