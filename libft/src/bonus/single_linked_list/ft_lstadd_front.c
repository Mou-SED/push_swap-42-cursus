/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:35:18 by moseddik          #+#    #+#             */
/*   Updated: 2022/03/03 15:11:15 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		new->next = *alst;
		*alst = new;
	}
}
