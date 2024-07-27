/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:06:12 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/27 19:17:17 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

//TODO: ft_handle_error()
//---------------------------------------------------------------//
// In case of error, it must display "Error" 
// followed by a ’\n’ on the standard error.
//---------------------------------------------------------------//
void ft_handle_error(int err_code, char *err_text)
{
	ft_printf("Error\n");
}

//TODO: ft_validate()
//---------------------------------------------------------------//
// func that validates input:
// NO duplicates
// ONLY Numbers
// INT limits
// it should return the code status 200 is OK 4** is KO
//---------------------------------------------------------------//
int ft_validate()
{

}

//TODO: ft_process_input
//---------------------------------------------------------------//
// func that validates input + restructurize it with split
// all in all it might create numbers_linked_list
// it should return the code status 200:OK - 4**:KO
//---------------------------------------------------------------//
int	ft_process_input(int argc, char **argv, t_numbers_list *list_a, t_numbers_list *list_b)
{
	
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
	process_input(argc, argv, &list_a, &list_b);
	
	return (0);
}