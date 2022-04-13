/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/13 00:03:35 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int optimaze_len(t_stk top, int pivot, int len)
{
    int i;
    int skip_len;
    t_d_list    *tmp;

    i = 0;
    skip_len = 0;
    tmp = ft_d_lstlast(top.stk_a);
    while(tmp && tmp->content > pivot)
    {
        tmp = tmp->prev;
        ++skip_len;
    }
    return (len - skip_len);
}

void    quick_sort_a(t_stk  *top)
{
    t_d_list *tmp;
    int pivot;
    int optimaze_length;
    
    top->len_by_flag = len_stack_by_flag(top->stk_a, top->stk_a->flag);
    pivot = find_mid(*top->stk_a, len_stack_by_flag(top->stk_a, top->stk_a->flag));
    optimaze_length = optimaze_len(*top, pivot, top->len_by_flag);
    printf("pivot :%d", pivot);
    tmp = top->stk_a;
    while(tmp && top->len_by_flag)
    {
        if (tmp->flag != 0)
            tmp = tmp->next;
        else
        {
            if (tmp->content <= pivot)
                PB;
            else if (tmp->content >= pivot)
                RA;
            --optimaze_length;
            if(!check_mid(tmp, pivot, 'a') || optimaze_length == 0)
                break ;
            tmp = tmp->next;
        }
        --top->len_by_flag;
    }
}

//! ********************************Quick_B*************************************

void    quick_sort_b(t_stk  *top)
{
    t_d_list *tmp;
    int pivot;
    
    pivot = find_mid(*top->stk_b, len_stk(*top->stk_b));
    printf("pivot_b :%d", pivot);
    
    tmp = top->stk_b;
    while(tmp)
    {
        if (tmp->content >= pivot)
        {
            top->stk_b->flag++;
            PA;
        }
        else if (tmp->content < pivot)
            RB;
        if(!check_mid(tmp, pivot, 'b'))
            break ;
        tmp = tmp->next;
    }
}

//! ****************************************************************************

void    normalize_b(t_stk  *top)
{
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

void    rra_nums_of_flag_zero(t_stk  *top)
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

void    ra_top_num(t_stk  *top)
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

void    quick_sort(t_stk  *top, int value)
{
    int with_flag_zero;

    if (value == 0)
    {
        quick_sort_a(top);
        quick_sort_b(top);
        // normalize_b(top);
        // quick_sort_a(top);
        // rra_nums_of_flag_zero(top);
        // normalize_b(top);
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
