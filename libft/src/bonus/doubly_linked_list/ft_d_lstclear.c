/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 23:29:36 by moseddik          #+#    #+#             */
/*   Updated: 2022/02/26 00:00:12 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_d_lstclear(t_d_list **lst, void (*del)(void *))
{
	t_d_list	*tmp;

	while (*lst != NULL)
	{
		tmp = (*lst)->next;
		ft_d_lstdelone(*lst, del);
		*lst = tmp;
	}
}
