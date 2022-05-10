/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:13:53 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/09 21:21:38 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	move_next_to_sort(t_stk *top)
{
	display_actions(ra, "ra\n", top);
	++top->next_one;
	top->next_to_sort = top->sorted_array[top->next_one];
}

void	choise_rotate_or_revrotate(t_stk *top, int len)
{
	t_d_list	*tmp;
	int			divide_length;
	int			count_content;

	divide_length = len / 2;
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
		display_actions(rb, "rb\n", top);
	else
		display_actions(rrb, "rrb\n", top);
}

int	len_above_first_sort(t_stk *top, int flag)
{
	t_d_list	*tmp;
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

static int	push_next_sort_a_helper(t_stk *top)
{
	if (top->stk_b->next == NULL)
	{
		display_actions(pa, "pa\n", top);
		if (top->stk_a->content == top->next_to_sort)
			move_next_to_sort(top);
		return (1);
	}
	else if (top->stk_b->content < top->stk_b->next->content)
	{
		display_actions(pa, "pa\n", top);
		if (top->stk_a->content == top->next_to_sort)
			move_next_to_sort(top);
	}
	else if (top->stk_b->content > top->stk_b->next->content)
	{
		display_actions(sb, "sb\n", top);
		display_actions(pa, "pa\n", top);
		if (top->stk_a->content == top->next_to_sort)
			move_next_to_sort(top);
	}
	return (0);
}

void	push_next_sort_a(t_stk *top)
{
	if (top->stk_b != NULL)
		top->len_b = len_stk(*top->stk_b);
	while (!is_empty(top->stk_b))
	{
		if (top->stk_b->content == top->next_to_sort)
		{
			display_actions(pa, "pa\n", top);
			move_next_to_sort(top);
		}
		else
		{
			if (top->len_b > 2)
				choise_rotate_or_revrotate(top, len_stk(*top->stk_b));
			else if (push_next_sort_a_helper(top) == 1)
				break ;
		}
	}
}
