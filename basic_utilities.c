/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:46:59 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/02 21:53:37 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
				while (copy_arr[i])
				{
					free(copy_arr[i]);
					i--;
				}
				free(copy_arr);
				return (NULL);
			}
		ft_strlcpy(temp, arr_of_arr[i], ft_strlen(arr_of_arr[i]) + 1);
		copy_arr[i - 1] = temp;
		i++;
	}
	copy_arr[argc - 1] = NULL;
	return (copy_arr);
}

// ft_get_size_of_super_arr()
//---------------------------------------------------------------//
// Returns back size of elemets in 2D array
//---------------------------------------------------------------//
int	ft_get_size_of_super_arr(char **super_arr)
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

// ft_list_length()
//---------------------------------------------------------------//
// returns amount of nodes inside of given List
//---------------------------------------------------------------//
int	ft_list_length(t_numbers_list *list)
{
    t_numbers_list	*temp;
	int				length;

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

// int main(int argc, char **argv)
// {
// 	int i;
// 	char **test = ft_copy_complex_arr(argc, argv);
// 	i = 0;
// 	while (test[i])
// 	{
// 		ft_printf("%s\n", test[i]);
// 		free(test[i]);
// 		i++;
// 	}
// 	free(test);
// 	return (0);
// }

