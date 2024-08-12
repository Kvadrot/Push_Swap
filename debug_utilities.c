/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itykhono <itykhono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 17:03:29 by itykhono          #+#    #+#             */
/*   Updated: 2024/08/12 14:04:15 by itykhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_debug_num_printer(t_numbers_list *list, char *separator_text)
{
	ft_printf("\n");
	ft_printf("||||||||||||||===== %s ======||||||||||||\n", separator_text);
	if (!list)
		ft_printf("LIST IS EMPTY DURA!!\n");
	while (list)
	{
		ft_printf("list %d, indx: %d", list->number, list->list_indx);
		if (list->target)
			ft_printf(" target: %d, target_ind: %d", list->target->number,
				list->target->list_indx);
		ft_printf(" shift_cost: %d", list->shifiting_cost);
		ft_printf("\n");
		list = list->next;
	}
}
