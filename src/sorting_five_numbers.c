/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_five_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:01:37 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/09 18:16:26 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	find_next_to_sort(t_stk *top)
{
	int			count;
	t_d_list	*tmp;

	count = 0;
	top->next_to_sort = top->sorted_array[top->next_one];
	tmp = top->stk_a;
	while (tmp != NULL && tmp->content != top->next_to_sort)
	{
		++count;
		tmp = tmp->next;
	}
	return (count);
}

static void	rotate_stack(t_stk *top, int count)
{
	int	divide_length;

	divide_length = len_stk(*top->stk_a) / 2;
	if (count <= divide_length)
	{
		while (top->stk_a->content != top->next_to_sort)
			display_actions(ra, "ra\n", top);
	}
	else
	{
		while (top->stk_a->content != top->next_to_sort)
			display_actions(rra, "rra\n", top);
	}
	display_actions(pb, "pb\n", top);
	++top->next_one;
}

void	sorting_five_numbers(t_stk *top)
{
	int	count;

	count = find_next_to_sort(top);
	rotate_stack(top, count);
	count = find_next_to_sort(top);
	rotate_stack(top, count);
	sorting_three_numbers(top);
	display_actions(pa, "pa\n", top);
	display_actions(pa, "pa\n", top);
}
