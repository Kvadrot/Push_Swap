/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:46:59 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/12 14:18:39 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ft_to_abs
//---------------------------------------------------------------//
// converts any int into long long int and multyplies by -1 if 
// num < 0
//---------------------------------------------------------------//
long long int ft_long_long_abs(long long int n)
{
	long long int	new_num;

	new_num = n;
	if (new_num < 0)
		return (new_num * -1);
	return (new_num);
}

// ft_to_abs
//---------------------------------------------------------------//
// converts any int and multyplies by -1 if num < 0
//---------------------------------------------------------------//
int	ft_abs(int n)
{
	int	new_num;

	new_num = n;
	if (new_num < 0)
		return (new_num * -1);
	return (new_num);
}


