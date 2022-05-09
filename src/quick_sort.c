/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/05 14:00:49 by moseddik         ###   ########.fr       */
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
		if (tmp->content == top->next_to_sort)
			break ;
		++count_content;
		tmp = tmp->next;
	}
	len = len - count_content;
	if (len >= divide_length)
		RB;
	else
		RRB;
}

void    begin_sort(t_stk  *top)
{
	static int	remember_first_sort;

	top->next_to_sort = top->sorted_array[top->next_one];
	if (remember_first_sort == 0)
	{
		top->first_sort = top->next_to_sort;
		++remember_first_sort;
	}
	top->pivot = find_mid(top, top->len_a, 'a');
	while(top->stk_a)
	{
		if (top->stk_a->content <= top->pivot)
			PB;
		else if (top->stk_a->content > top->pivot)
			RA;
		if(!check_mid(top->stk_a, top->pivot, 'a'))
			break ;
	}
	while (!is_empty(top->stk_b))
		quick_sort_b(top);
	//TODO: you have to move it!
	while (top->stk_a->content == top->next_to_sort)
		move_next_to_sort(top);
	part1_sort(top);
}

//! ********************************Quick_B*************************************

void    quick_sort_b(t_stk  *top)
{
	static int 	flg;

	top->pivot = find_mid(top, len_stk(*top->stk_b), 'b');
	++flg;

	while(top->stk_b)
	{
		if (top->stk_b->content >= top->pivot || len_stk(*top->stk_b) == 1)
		{
			top->stk_b->flag = flg;
			PA;
		}
		else if (top->stk_b->content < top->pivot && top->stk_b->content == top->next_to_sort)
		{
			top->stk_b->flag = flg;
			PA;
			move_next_to_sort(top);
		}
		else if (top->stk_b->content < top->pivot && top->stk_b->content != top->next_to_sort)
			choise_rotate_or_revrotate(top, len_stk(*top->stk_b));
		if(!check_mid(top->stk_b, top->pivot, 'b'))
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

	count = 0;
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
		if (top->stk_b->content == top->next_to_sort)
		{
			PA;
			move_next_to_sort(top);
		}
		else
		{
			if (top->len_b > 2)
				choise_rotate_or_revrotate(top, len_stk(*top->stk_b));
			else
			{
				if (top->stk_b->next == NULL)
				{
					PA;
					if (top->stk_a->content == top->next_to_sort)
						move_next_to_sort(top);
					break ;
				}
				else if (top->stk_b->content < top->stk_b->next->content)
				{
					PA;
					if (top->stk_a->content == top->next_to_sort)
						move_next_to_sort(top);
				}
				else if (top->stk_b->content > top->stk_b->next->content)
				{
					SB;
					PA;
					if (top->stk_a->content == top->next_to_sort)
						move_next_to_sort(top);
				}
			}
		}
	}
}

void    part1_sort(t_stk  *top)
{
	if (is_sorted(top->stk_a))
		return ;
	while(top->stk_a && top->stk_a->flag != 0)
	{
		while (top->stk_a->content == top->next_to_sort)
			move_next_to_sort(top);
		if (top->stk_a->content != top->next_to_sort && top->stk_a->flag != 0)
			PB;
		else if (top->stk_a->content == top->next_to_sort && top->stk_a->flag != 0)
			move_next_to_sort(top);
		if (top->stk_a->flag == 0)
			break ;
	}
	push_next_sort_a(top);
}

void    part2_sort(t_stk  *top)
{
	int count_ra;
	

	count_ra = 0;
	top->pivot = find_mid(top, len_stack_by_flag(top->stk_a, top->stk_a->flag), 'a');

	while(top->stk_a)
	{
		if (top->stk_a->content <= top->pivot)
			PB;
		else if (top->stk_a->content > top->pivot)
		{
			RA;
			++count_ra;
		}
		if(!check_mid(top->stk_a, top->pivot, 'a') || top->stk_a->flag != 0)
			break ;
	}
	while (count_ra && ft_d_lstlast(top->stk_a)->flag == 0)
	{
		--count_ra;
		RRA;
	}
	while (!is_empty(top->stk_b))
		quick_sort_b(top);
	while (top->stk_a->content == top->next_to_sort)
		move_next_to_sort(top);
	part1_sort(top);
}

void	main_sorting(t_stk  *top, int value)
{
	if (value == 0)
		begin_sort(top);
	if (value == 1)
	{
		while (len_stack_by_flag(top->stk_a, 0) && len_stack_by_flag(top->stk_a, 0) >= 6 && !is_sorted(top->stk_a))
		{
			part2_sort(top);
			if (len_stack_by_flag(top->stk_a, 0) <= 6 || is_sorted(top->stk_a))
				break ;
		}
		while (top->stk_a->flag == 0)
			PB;
		push_next_sort_a(top);
	}
}
