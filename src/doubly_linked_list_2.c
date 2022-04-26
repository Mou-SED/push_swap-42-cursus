/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:16:09 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/26 00:09:40 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_d_lstdelone(t_d_list *lst, void (*del) (void *))
{
	if (!lst || del == NULL)
		return ;
	free(lst);
}

void	ft_d_lstclear(t_d_list **lst, void (*del)(void *))
{
	t_d_list	*tmp;

    if (del == NULL || lst == NULL)
        return ;
	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_d_lstdelone(tmp, del);
	}
}
