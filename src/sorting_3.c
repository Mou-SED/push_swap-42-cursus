/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:21:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/12 22:56:00 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    sorting_3(t_stk *top)
{
    while (!is_sorted(top->stk_a))
    {
        if (top->stk_a->content > top->stk_a->next->content && top->stk_a->content > ft_d_lstlast(top->stk_a)->content)
            RA;
        else if (ft_d_lstlast(top->stk_a)->prev->content > ft_d_lstlast(top->stk_a)->content)
            RRA;
        else if (top->stk_a->content > top->stk_a->next->content)
            SA;
        else if (ft_d_lstlast(top->stk_a)->content < top->stk_a->content)
            RRA;
    }
}