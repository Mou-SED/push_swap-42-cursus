/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:21:18 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/10 08:22:05 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	part1_sort(t_stk *top)
{
	if (is_sorted(top->stk_a))
		return ;
	while (top->stk_a && top->stk_a->flag != 0)
	{
		while (top->stk_a->content == top->next_to_sort)
			move_next_to_sort(top);
		if (top->stk_a->content != top->next_to_sort && top->stk_a->flag != 0)
			display_actions(pb, "pb\n", top);
		else if (top->stk_a->content == top->next_to_sort
			&& top->stk_a->flag != 0)
			move_next_to_sort(top);
		if (top->stk_a && top->stk_a->flag == 0)
			break ;
	}
	push_next_sort_a(top);
}

static void	rra_big_numbers(t_stk *top, int *count_ra)
{
	while (*count_ra && ft_d_lstlast(top->stk_a)->flag == 0)
	{
		--(*count_ra);
		display_actions(rra, "rra\n", top);
	}
}

void	part2_sort(t_stk *top)
{
	int	count_ra;

	count_ra = 0;
	top->pivot
		= find_mid(top, len_stack_by_flag(top->stk_a, top->stk_a->flag), 'a');
	while (top->stk_a)
	{
		if (top->stk_a->content <= top->pivot)
			display_actions(pb, "pb\n", top);
		else if (top->stk_a->content > top->pivot)
		{
			display_actions(ra, "ra\n", top);
			++count_ra;
		}
		if (!check_mid(top->stk_a, top->pivot, 'a') || top->stk_a->flag != 0)
			break ;
	}
	rra_big_numbers(top, &count_ra);
	while (!is_empty(top->stk_b))
		quick_sort_b(top);
	while (top->stk_a->content == top->next_to_sort)
		move_next_to_sort(top);
	part1_sort(top);
}
