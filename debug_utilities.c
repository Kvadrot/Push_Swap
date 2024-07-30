/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:03:29 by itykhono          #+#    #+#             */
/*   Updated: 2024/07/30 18:48:50 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_debug_num_printer(t_numbers_list *list, char *separator_text)
{
	ft_printf("||||||||||||||===== %s ======||||||||||||\n", separator_text);
	if (!list)
		ft_printf("LIST IS EMPTY DURA!!\n");
	while (list)
	{
		ft_printf("list %d\n", list->number);
		list = list->next;
	}
}