/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three_numbers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:21:34 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/09 16:00:41 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sorting_three_numbers(t_stk *top)
{
	int	first;
	int	second;
	int	third;

	while (!is_sorted(top->stk_a))
	{
		first = top->stk_a->content;
		second = top->stk_a->next->content;
		third = top->stk_a->next->next->content;
		if (first > second && first > third)
			display_actions(ra, "ra\n", top);
		else if (second > third)
			display_actions(rra, "rra\n", top);
		else if (first > second)
			display_actions(sa, "sa\n", top);
		else if (third < first)
			display_actions(rra, "rra\n", top);
	}
}
