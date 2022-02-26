/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 00:01:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/02/26 00:27:37 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_d_list	*ft_d_lstnew(void *content)
{
	t_d_list	*head;

	head = malloc(sizeof(head));
	if (!head)
		return (NULL);
	head->prev = NULL;
	head->content = content;
	head->next = NULL;
	return (head);
}
