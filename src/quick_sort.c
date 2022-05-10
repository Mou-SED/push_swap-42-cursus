/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:37:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/10 08:44:39 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	begin_sort(t_stk *top)
{
	static int	remember_first_sort;

	top->next_to_sort = top->sorted_array[top->next_one];
	if (remember_first_sort == 0)
	{
		top->first_sort = top->next_to_sort;
		++remember_first_sort;
	}
	top->pivot = find_mid(top, top->len_a, 'a');
	while (top->stk_a)
	{
		if (top->stk_a->content <= top->pivot)
			display_actions(pb, "pb\n", top);
		else if (top->stk_a->content > top->pivot)
			display_actions(ra, "ra\n", top);
		if (!check_mid(top->stk_a, top->pivot, 'a'))
			break ;
	}
	while (!is_empty(top->stk_b))
		quick_sort_b(top);
	while (top->stk_a->content == top->next_to_sort)
		move_next_to_sort(top);
	part1_sort(top);
}

void	quick_sort_b(t_stk *top)
{
	static int	flg;

	top->pivot = find_mid(top, len_stk(*top->stk_b), 'b');
	++flg;
	while (top->stk_b)
	{
		if (top->stk_b->content >= top->pivot || len_stk(*top->stk_b) == 1)
		{
			top->stk_b->flag = flg;
			display_actions(pa, "pa\n", top);
		}
		else if (top->stk_b->content < top->pivot
			&& top->stk_b->content == top->next_to_sort)
		{
			top->stk_b->flag = flg;
			display_actions(pa, "pa\n", top);
			move_next_to_sort(top);
		}
		else if (top->stk_b->content < top->pivot)
			choise_rotate_or_revrotate(top, len_stk(*top->stk_b));
		if (!check_mid(top->stk_b, top->pivot, 'b'))
			break ;
		if (is_sorted(top->stk_a) && is_empty(top->stk_b))
			return ;
	}
}

void	main_sorting(t_stk *top, int value)
{
	if (value == 0)
		begin_sort(top);
	if (value == 1)
	{
		while (len_stack_by_flag(top->stk_a, 0) >= 10 && !is_sorted(top->stk_a))
		{
			part2_sort(top);
			if (len_stack_by_flag(top->stk_a, 0) <= 10 || is_sorted(top->stk_a))
				break ;
		}
		while (top->stk_a->flag == 0)
			display_actions(pb, "pb\n", top);
		push_next_sort_a(top);
	}
}
