/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/20 21:53:57 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	choise_rotate_or_revrotate(t_stk  *top, int len, char c)
{
	t_d_list    *tmp;
	int		divide_length;
	int		count_content;
	
	divide_length = len/2;
	count_content = 0;
	if (c == 'a')
		tmp = top->stk_a;
	else if (c == 'b')
		tmp = top->stk_b;
	while (tmp)
	{
		if (tmp->content != top->next_to_sort)
		{
			count_content++;
			tmp = tmp->next;
		}
		else			
			break ;
	}
	len = len - count_content;
	if (len >= divide_length)
	{
		if (c == 'a')
			RA;
		else if (c == 'b')
			RB;
	}
	else
	{
		if (c == 'a')
			RRA;
		else if (c == 'b')
			RRB;
	}
}

void    quick_sort_a(t_stk  *top)
{
	t_d_list *tmp;
	int pivot;
	static int next_one;
	int *sorted_array;
	
	sorted_array = content_of_next(top);
	top->len_by_flag = len_stack_by_flag(top->stk_a, top->stk_a->flag);
	pivot = find_mid(*top->stk_a, len_stack_by_flag(top->stk_a, top->stk_a->flag));
	
	tmp = top->stk_a;
	while(tmp && top->len_by_flag)
	{
		if (tmp->flag != 0)
			tmp = tmp->next;
		else
		{
			if (tmp->content <= pivot)
				PB;
			else if (tmp->content > pivot)
				RA;
			if(!check_mid(tmp, pivot, 'a'))
				break ;
			tmp = tmp->next;
		}
		--top->len_by_flag;
	}
	while (!is_empty(top->stk_b))
	    quick_sort_b(top, &next_one, sorted_array);
		
	//TODO: you have to move it!
	while (top->stk_a->content == top->next_to_sort)
	{
		RA;
		++(next_one);
		top->next_to_sort = sorted_array[next_one];
	}
	while(top->stk_a->content != top->value_of_flag_zero)
		quick_sort_a_2(top, &next_one, sorted_array);
}

//! ********************************Quick_B*************************************

void    quick_sort_b(t_stk  *top, int *next_one, int *sorted_array)
{
	t_d_list	*tmp;
	int 		pivot;
	static int 	flg;

	top->next_to_sort = sorted_array[*next_one];
	pivot = find_mid(*top->stk_b, len_stk(*top->stk_b));
	++flg;
	
	tmp = top->stk_b;
	while(tmp)
	{
		if (tmp->content >= pivot || len_stk(*top->stk_b) == 1)
		{
			top->stk_b->flag = flg;
			PA;
			tmp = top->stk_b;
		}
		else if (tmp->content < pivot && tmp->content == top->next_to_sort)
		{
			top->stk_b->flag = flg;
			PA;
			tmp = top->stk_b;
		}
		else if (tmp->content < pivot && tmp->content != top->next_to_sort)
		{
			RB;
			tmp = top->stk_b;
		}
		if (top->stk_a->content == top->next_to_sort)
		{   
			RA;
			++(*next_one);
			top->next_to_sort = sorted_array[*next_one];
		}
		if(!check_mid(tmp, pivot, 'b'))
			break ;
	}
}

//! ****************************************************************************

//! ********************************Quick_A_2***********************************

void    quick_sort_a_2(t_stk  *top, int *next_one, int *sorted_array)
{
	t_d_list *tmp;
	int pivot;
	// (void)next_one;
	// (void)sorted_array;
	
	pivot = find_mid(*top->stk_a, len_stk(*top->stk_a));
	
	top->top_flag_value = top->stk_a->flag;
	tmp = top->stk_a;
	while(tmp)
	{
		if (tmp->flag != top->top_flag_value)
			tmp = tmp->next;
		else
		{
			if (tmp->content <= pivot)
			{
				PB;
				tmp = top->stk_a;
			}
			if (tmp->content == top->next_to_sort)
			{
				RA;
				++(*next_one);
				top->next_to_sort = sorted_array[*next_one];
			}
			if(!check_mid(tmp, pivot, 'a'))
				break ;
		}
		if (tmp->flag == 0)
		{
			top->value_of_flag_zero = tmp->content;
			break ;
		}
	}
	
	int len_b = len_stk(*top->stk_b);
	while (!is_empty(top->stk_b))
	{
		if (top->stk_b->content == top->next_to_sort)
		{
			PA;
			RA;
			++(*next_one);
			top->next_to_sort = sorted_array[*next_one];
			len_b--;
		}
		else
		{
			if (len_stk(*top->stk_b) > 2)
				choise_rotate_or_revrotate(top, len_b, 'b');
			else
			{
				if (top->stk_b->next == NULL)
				{
					PA;
					break ;
				}
				else if (top->stk_b->content <= top->stk_b->next->content)
					PA;
				else
				{
					SA;
					PA;
				}
			}
		}
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
