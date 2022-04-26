/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/26 08:52:49 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_next_to_sort(t_stk  *top)
{
	RA;
	++top->next_one;
	top->next_to_sort = top->sorted_array[top->next_one];
}

void	choise_rotate_or_revrotate(t_stk  *top, int len)
{
	t_d_list	*tmp;
	int			divide_length;
	int			count_content;
	
	divide_length = len/2;
	count_content = 0;
	
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
		RB;
	else
		RRB;
}

void    begin_sort(t_stk  *top)
{
	t_d_list	*tmp;
	int			pivot;
	static int	remember_first_sort;

	top->next_to_sort = top->sorted_array[top->next_one];
	if (remember_first_sort == 0)
	{
		top->first_sort = top->next_to_sort;
		remember_first_sort++;
	}
	pivot = find_mid(top, len_stk(*top->stk_a), 0, 'a');
	tmp = top->stk_a;
	while(tmp)
	{
		tmp = top->stk_a;
		if (tmp->content <= pivot)
		{
			PB;
			if(len_stk(*top->stk_b) > 1)
			{
				if(top->stk_b->content == get_min_number(*top->stk_b))
					RB;
				if(top->stk_b->next->content > top->stk_b->content)
					SB;
			}
		}
		else if (tmp->content > pivot)
			RA;
		if(!check_mid(tmp, pivot, 'a'))
			break ;
	}
	while (!is_empty(top->stk_b))
		quick_sort_b(top);
	//TODO: you have to move it!
	while (top->stk_a->content == top->next_to_sort && !is_sorted(top->stk_a))
		move_next_to_sort(top);
	if (!is_sorted(top->stk_a))
		part1_sort(top);
}

//! ********************************Quick_B*************************************

void    quick_sort_b(t_stk  *top)
{
	t_d_list	*tmp;
	int 		pivot;
	static int 	flg;

	pivot = find_mid(top, len_stk(*top->stk_b), 0, 'b');
	++flg;
	
	tmp = top->stk_b;
	while(tmp)
	{
		if (top->stk_b->next != NULL && top->stk_b->next->content == top->next_to_sort)
			SB;
		if (tmp->content >= pivot || len_stk(*top->stk_b) == 1)
		{
			top->stk_b->flag = flg;
			PA; //? normalize_b(top);
			tmp = top->stk_b;
		}
		else if (tmp->content < pivot && tmp->content == top->next_to_sort)
		{
			top->stk_b->flag = flg;
			PA;
			move_next_to_sort(top);
			tmp = top->stk_b;
		}
		else if (tmp->content < pivot && tmp->content != top->next_to_sort)
		{
			choise_rotate_or_revrotate(top, top->len_b);
			tmp = top->stk_b;
		}
		if (top->stk_a->content == top->next_to_sort)  
			move_next_to_sort(top);
		if(!check_mid(tmp, pivot, 'b'))
			break ;
		if(is_sorted(top->stk_a) && is_empty(top->stk_b))
			return ;
	}
}

//! ****************************************************************************

int		len_above_first_sort(t_stk *top, int flag)
{
	t_d_list    *tmp;
	int			count;
	
	count = 1;
	tmp = top->stk_a;
	while (tmp && tmp->flag == flag)
	{
		if (tmp->content != top->first_sort)
		{
			count++;
			tmp = tmp->next;
		}
		else
			break ;
	}
	return (count);
}

//! ********************************Quick_A_2***********************************

void	push_next_sort_a(t_stk  *top)
{
	if (top->stk_b != NULL)
		top->len_b = len_stk(*top->stk_b);
	
	while (!is_empty(top->stk_b))
	{
		if (top->stk_b->next != NULL && top->stk_b->next->content == top->next_to_sort)
			SB;
		if (top->stk_b->content == top->next_to_sort)
		{
			PA;
			move_next_to_sort(top);
			top->len_b--;
		}
		else
		{
			if (top->len_b > 2)
				choise_rotate_or_revrotate(top, top->len_b);
			else
			{
				if (top->stk_b->next == NULL)
				{
					PA;
					break ;
				}
				else if (top->stk_b->content < top->stk_b->next->content)
					PA;
				else if (top->stk_b->content > top->stk_b->next->content)
				{
					SB;
					PA;
				}
			}
		}
	}
}

void    part1_sort(t_stk  *top)
{
	t_d_list	*tmp;
	int 		pivot;
	
	pivot = find_mid(top, len_above_first_sort(top, top->stk_a->flag), 1, 'a');
	
	tmp = top->stk_a;
	while(tmp)
	{
		while (top->stk_a->content == top->next_to_sort)
			move_next_to_sort(top);
		if (tmp->content != top->next_to_sort)
		{
			PB;
			tmp = top->stk_a;
		}
		if (tmp->content == top->next_to_sort)
			move_next_to_sort(top);
		if (top->stk_a->flag == 0)
			break ;
	}
	push_next_sort_a(top);
	if (top->stk_a->flag == 0 || top->stk_a->flag == 1)
		return ;
}

void    part2_sort(t_stk  *top)
{
	t_d_list 	*tmp;
	int 		pivot;

	pivot = find_mid(top, len_above_first_sort(top, top->stk_a->flag), 1, 'a');
	
	tmp = top->stk_a;
	while(tmp)
	{
		while (top->stk_a->content == top->next_to_sort 
			&& !is_sorted(top->stk_a) && top->stk_a->flag == 0)
			move_next_to_sort(top);
		if (tmp->content != top->next_to_sort)
		{
			PB;
			tmp = top->stk_a;
		}
		if (tmp->content == top->next_to_sort)
			move_next_to_sort(top);
		if (top->stk_a->flag != 0)
			break ;
	}
	push_next_sort_a(top);
	if (top->stk_a->flag != 0)
		return ;
}

//! ****************************normalize_b*************************************

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

//! ****************************************************************************

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

void	main_sorting(t_stk  *top, int value)
{
	if (value == 0)
		begin_sort(top);
	if (value == 1)
		part2_sort(top);
}
