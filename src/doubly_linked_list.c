/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:50:38 by moseddik          #+#    #+#             */
/*   Updated: 2022/03/29 17:56:52 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_d_list	*ft_d_lstnew(int content)
{
	t_d_list	*head;

	head = malloc(sizeof(t_d_list));
	if (!head)
		return (NULL);
	head->prev = NULL;
	head->content = content;
	head->next = NULL;
	return (head);
}

void	ft_d_lstadd_front(t_d_list **alst, t_d_list *new)
{
	if (!alst)
		return ;
	if (*alst == NULL)
		*alst = new;
	else
	{
		new->next = *alst;
    	(*alst)->prev = new;
    	*alst = new;
	}
}

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


t_d_list	*ft_d_lstlast(t_d_list *lst)
{
	t_d_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}


int	ft_d_lstsize(t_d_list *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}