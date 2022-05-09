/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:08:36 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/09 14:17:05 by moseddik         ###   ########.fr       */
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

int len_stack_by_flag(t_d_list *top, int flag)
{
	int len;
	
	len = 1;
	while (top && top->flag == flag)
	{
		++len;
		top = top->next;
	}
	return (len);
}

t_d_list	*duplicate_stack(t_d_list *top_stack, int len)
{
	t_d_list    *tmp;
	t_d_list    *head;

	tmp = ft_calloc(1, sizeof(t_d_list));
	if (tmp == NULL)
		return (NULL);
	head = tmp;
	while (top_stack && len)
	{
		tmp->content = top_stack->content;
		if (top_stack->next)
		{
			tmp->next = ft_calloc(1, sizeof(t_d_list));
			if (tmp->next == NULL)
				return (NULL);
			tmp = tmp->next;
		}
		top_stack = top_stack->next;
		--len;
	}
	return (head);
}

int is_empty(t_d_list *p_stack)
{
    if (p_stack == NULL)
        return (1);
    return (0);
}
