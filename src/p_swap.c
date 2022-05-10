/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_swap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 23:40:03 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/09 21:02:39 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	p_swap(t_d_list **top)
{
	int	tmp;

	if (top == NULL || is_empty(*top) || (*top)->next == NULL)
		return ;
	else
	{
		tmp = (*top)->next->content;
		(*top)->next->content = (*top)->content;
		(*top)->content = tmp;
	}
}

void	sa(t_d_list **top_a)
{
	p_swap(top_a);
}

void	sb(t_d_list **top_b)
{
	p_swap(top_b);
}

void	p_sswap(t_d_list **top_a, t_d_list **top_b)
{
	p_swap(top_a);
	p_swap(top_b);
}
