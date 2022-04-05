/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_push.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:04:35 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/03 14:33:41 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    p_push(t_d_list **top_to_get, t_d_list **top_to_add)
{
	t_d_list *tmp;
	t_d_list *node;

	if (is_empty(*top_to_get))
		return ;
	if (is_empty(*top_to_add))
	{
		(*top_to_add) = ft_d_lstnew((*top_to_get)->content);
		tmp = (*top_to_get);
		(*top_to_add)->flag = tmp->flag;
		(*top_to_get) = (*top_to_get)->next;
		(*top_to_get)->prev = NULL;
		free(tmp);
	}
	else
	{
		tmp = ft_d_lstnew((*top_to_get)->content);
		node = *top_to_get;
		tmp->flag = node->flag;
		(*top_to_get) = (*top_to_get)->next;
		free(node);
		ft_d_lstadd_front(top_to_add, tmp);
	}
}

void	pa(t_d_list **top_a, t_d_list **top_b)
{
	p_push(top_b, top_a);
}

void	pb(t_d_list **top_a, t_d_list **top_b)
{
	p_push(top_a, top_b);
}
