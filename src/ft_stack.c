/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:08:36 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/25 23:45:54 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_d_list *create_stack_a(t_d_list *top_a, char *str)
{
	int			data;
	t_d_list	*new_node;

	data = ft_atoi(str);
	new_node = ft_d_lstnew(data);
	if (new_node == NULL)
	{
		ft_d_lstclear(&top_a, &free);
		return (NULL);
	}
	ft_d_lstadd_back(&top_a, new_node);
	return (top_a);
}

int len_stk(t_d_list stack)
{
	int len;
	t_d_list *stk;

	len = 0;
	stk = &stack;
	while (stk)
	{
		++len;
		stk = stk->next;
	}
	return (len);
}

t_d_list	*duplicate_stack(t_d_list *top, int len)
{
	t_d_list    *tmp;
	t_d_list    *head;

	tmp = ft_calloc(1, sizeof(t_d_list));
	if (tmp == NULL)
		return (NULL);
	head = tmp;
	while (top && len)
	{
		tmp->content = top->content;
		if (top->next)
		{
			tmp->next = ft_calloc(1, sizeof(t_d_list));
			if (tmp->next == NULL)
				return (NULL);
			tmp = tmp->next;
		}
		top = top->next;
		--len;
	}
	tmp = head;
	return (tmp);
}

int len_stack_by_flag(t_d_list *top, int flag)
{
	int len;
	
	len = 0;
	while (top && top->flag == flag)
	{
		++len;
		top = top->next;
	}
	return (len);
}
