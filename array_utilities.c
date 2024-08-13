/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:14:53 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/13 13:46:19 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_free_complex_array
//---------------------------------------------------------------//
// frees any array of type **type
//---------------------------------------------------------------//
void	ft_free_complex_array(void **array)
{
	int	ind;

	ind = 0;
	while (array[ind])
	{
		free(array[ind]);
		ind++;
	}
	free(array);
}

// ft_copy_complex_arr
//---------------------------------------------------------------//
// coppies all elments from char ** into new char**
//---------------------------------------------------------------//
char	**ft_copy_complex_arr(int argc, char **arr_of_arr)
{
	char	**copy_arr;
	char	*temp;
	int		i;

	i = 1;
	copy_arr = (char **)malloc((argc) * sizeof(char *));
	if (!copy_arr)
		return (NULL);
	while (i < argc)
	{
		temp = (char *)malloc(sizeof(char) * ft_strlen(arr_of_arr[i]) + 1);
		if (!temp)
		{
			ft_free_complex_array((void **)copy_arr);
			return (NULL);
		}
		ft_strlcpy(temp, arr_of_arr[i], ft_strlen(arr_of_arr[i]) + 1);
		copy_arr[i - 1] = temp;
		i++;
	}
	copy_arr[argc - 1] = NULL;
	return (copy_arr);
}

// ft_len_super_arr()
//---------------------------------------------------------------//
// Returns back size of elemets in 2D array
//---------------------------------------------------------------//
int	ft_len_super_arr(char **super_arr)
{
	int	i;

	i = 0;
	if (!super_arr)
		return (i);
	else
	{
		while (super_arr[i] != NULL)
			i++;
	}
	return (i);
}
