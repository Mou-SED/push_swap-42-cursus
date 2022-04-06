/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/06 16:25:27 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void    quick_sort_a(p_stk  *top)
{
    int pivot;
    top->len_by_flag = len_stack_by_flag(top->stk_a, top->stk_a->flag);
    pivot = find_mid(*top->stk_a, len_stack_by_flag(top->stk_a, top->stk_a->flag));

    t_d_list *tmp;

    tmp = top->stk_a;
    while(tmp && top->len_by_flag)
    {
        if (tmp->flag != 0)
            tmp = tmp->next;
        else
        {
            if (tmp->content <= pivot)
                PB;
            else
                RA;
            if(top->stk_b && top->stk_b->next && top->stk_b->content < top->stk_b->next->content)
                SB;
            if(!check_mid(tmp, pivot))
                break ;
            tmp = tmp->next;
        }
        --top->len_by_flag;
    }
}

void    normalize_b(p_stk  *top)
{
    //if (top.stk_b)
    //    pivot = find_mid(*top.stk_b, len_stk(*top.stk_b));
    while(top->stk_b)
    {
        while(top->stk_b->content != get_min_number(*top->stk_b))
            stk_normalize(&top->stk_b, len_stk(*top->stk_b));
        if(top->stk_b->content == get_min_number(*top->stk_b))
        {
            top->stk_b->flag++;
            PA;
            RA;
        }
    }
}

void    rra_nums_of_flag_zero(p_stk  *top)
{
    t_d_list    *tmp;
    
    tmp = top->stk_a;
    while(tmp)
    {
        while (tmp->flag == 0)
        {
            tmp = ft_d_lstlast(tmp);
            tmp = tmp->prev;
            RRA;
        }
        tmp = tmp->next;
    }
}

void    ra_top_num(p_stk  *top)
{
    t_d_list    *tmp;
    
    tmp = top->stk_a;
    if (tmp && tmp->flag == 0 && tmp->next != 0)
    {
        top->stk_a->flag++;
        RA;
    }
}

int    check_sort(t_d_list **a)
{
    t_d_list    *tmp;

    tmp = *a;
    while (tmp && tmp->next)
    {
        if ((tmp)->next != NULL && ((tmp)->content < (tmp)->next->content))
            (tmp) = tmp->next;
        else
            return (0);
    }
    return (1);
}

int number_of_int_with_flag_zero(t_d_list top_a)
{
    int value;
    t_d_list *tmp;
    
    value = 0;
    tmp = &top_a;
    while (tmp)
    {
        if(tmp->flag == 0)
            value++;
        tmp = tmp->next;   
    }
    return (value);
}

void    quick_sort(p_stk  *top, int value)
{
    int with_flag_zero;

    if (value == 0)
    {
        quick_sort_a(top);
        normalize_b(top);
        quick_sort_a(top);
        rra_nums_of_flag_zero(top);
        normalize_b(top);
    }
    if (value == 1)
    {
        while (!is_sorted(top->stk_a))
        {
            quick_sort_a(top);
            rra_nums_of_flag_zero(top);
            normalize_b(top);
            with_flag_zero = number_of_int_with_flag_zero(*top->stk_a);
            if (with_flag_zero == 1)
            {
                top->stk_a->flag++;
                RA;
            }
        }  
    }
}
