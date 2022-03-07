/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 18:39:14 by moseddik          #+#    #+#             */
/*   Updated: 2022/03/03 15:12:14 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstadd_back(t_d_list **alst, t_d_list *new)
{
	t_d_list	*ptr;
	
	if (!alst)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		ptr = *alst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
        new->prev = ptr;
		new->next = NULL;
	}
}