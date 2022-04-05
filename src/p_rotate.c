/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:38:35 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/03 14:30:39 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    p_rotate(t_d_list **top)
{
    int value;
    t_d_list *new_node;
    
    if (top == NULL || is_empty(*top) || (*top)->next == NULL)
        return ;
    else
    {
        *top = (*top)->next;
        value = (*top)->prev->content;
        new_node = ft_d_lstnew(value);
        new_node->flag = (*top)->prev->flag;
        ft_d_lstadd_back(top, new_node);
        free((*top)->prev);
        (*top)->prev = NULL;
    }
}

void    ra(t_d_list **top_a)
{
    p_rotate(top_a);
}

void    rb(t_d_list **top_b)
{
    p_rotate(top_b);
}

void    p_rrotate(t_d_list **top_a, t_d_list **top_b)
{
    p_rotate(top_a);
    p_rotate(top_b);
}