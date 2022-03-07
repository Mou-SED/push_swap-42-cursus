/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:48:35 by moseddik          #+#    #+#             */
/*   Updated: 2022/03/03 15:12:00 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;
	
	if (!alst)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		ptr = *alst;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new;
		new->next = NULL;
	}
}
