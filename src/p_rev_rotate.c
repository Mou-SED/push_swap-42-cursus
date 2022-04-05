/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rev_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:38:56 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/03 14:31:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    p_rev_rotate(t_d_list **top)
{
    t_d_list *last_node;

    if (top == NULL || is_empty(*top) || (*top)->next == NULL)
        return ;
    else
    {
        last_node = *top;
        while (last_node->next != NULL)
            last_node = last_node->next;
        last_node->prev->next = NULL;
        last_node->next = NULL;
        last_node->prev = NULL;
        ft_d_lstadd_front(top, last_node); 
    }
}

void    rra(t_d_list **top_a)
{
    p_rev_rotate(top_a);   
}

void    rrb(t_d_list **top_b)
{
    p_rev_rotate(top_b);   
}

void    p_rrev_rotate(t_d_list **top_a, t_d_list **top_b)
{
    p_rev_rotate(top_a);
    p_rev_rotate(top_b);
}
