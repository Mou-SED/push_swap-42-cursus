/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:21:32 by moseddik          #+#    #+#             */
/*   Updated: 2022/03/28 15:58:28 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int normalize(t_d_list stk, int len)
{
	t_d_list *tmp;
	int i;
	int min;

	min = get_min_number(stk);
	tmp = &stk;
	i = 0;
	while(tmp != NULL)
	{
		if(tmp->content == min)
			break ;
		i++;
		tmp = tmp->next;
	}
	if(i >= len/2)
		return (1);
	return (0);
}

void stk_normalize(t_d_list **stk, int len)
{
	if(normalize(**stk, len))
		p_rev_rotate(stk);
	else
		p_rotate(stk);
}