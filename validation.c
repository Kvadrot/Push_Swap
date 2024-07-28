/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 18:37:53 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/28 18:39:36 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//TODO: ft_is_valid_duplicates()
//---------------------------------------------------------------//
// func that validates input:
// NO DUPLICATES are allowed
//---------------------------------------------------------------//
bool	ft_is_valid_duplicates(int *numbers, int numbers_amount)
{
	int	i;
	int	ind;

	i = 0;
	while (i < numbers_amount)
	{
		ind = i + 1;
		while (ind < numbers_amount)
		{
			if (numbers[i] == numbers[ind])
				return (false);
			ind++;
		}
		ft_printf("there are no duplicates for %d \n", numbers[i]);
		i++;
	}
	return (true);
}

//TODO: ft_is_valid_limts()
//---------------------------------------------------------------//
// func that validates input:
// input must be between INT_MAX INT_MIN
//---------------------------------------------------------------//
bool	ft_is_valid_limts(char **args)
{
	char	*max_int;
	char	*min_int;
	int		i;

	i = 0;
	max_int = "2147483647";
	min_int = "-2147483648";

	while (args[i])
	{
		if (args[i][0] == '-')
		{
			if (ft_strlen(args[i]) > ft_strlen(min_int))
				return (false);
			else if (ft_strlen(min_int) == ft_strlen(args[i]) && ft_memcmp(min_int, args[i], ft_strlen(min_int)) < 0)
				return (false);
		}
		else if (args[i][0] == '+')
		{
			if (ft_strlen(args[i]) > ft_strlen(max_int) + 1)
				return (false);
			else if (ft_strlen(max_int) + 1 == ft_strlen(args[i]) && ft_memcmp(max_int, args[i], ft_strlen(max_int) + 1) < 0)
				return (false);
		} 
		else if (ft_strlen(args[i]) > ft_strlen(max_int))
				return (false);
		else if (ft_strlen(max_int) == ft_strlen(args[i]) && ft_memcmp(max_int, args[i], ft_strlen(max_int)) < 0)
				return (false);
		ft_printf("limit requirments are met for: %s\n", args[i]);
		i++;
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
int	*ft_validate_and_convert(char **arguments, int *processed_size)
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
	result = (int *)malloc(sizeof(int) * ft_get_size_of_super_arr(arguments) + 1);
	if (!result)
		return (NULL);

	while (arguments[i])
	{
		result[i] = atoi(arguments[i]);
		i++;
	}
	*processed_size = i;
	if (ft_is_valid_duplicates(result, i) == false)
		return (NULL);
	return (result);
}