/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:35:08 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/09 20:58:18 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_create_stack(t_stk *top, char **av)
{
	int	i;

	ft_bzero(top, sizeof(t_stk));
	i = 0;
	top->spl = join_args(av);
	if (top->spl == NULL)
		return (-1);
	check_dupl_args(top->spl);
	while (top->spl[++i] != NULL)
	{
		if (check_error(top->spl[i]) || check_error_overflow(top->spl[i]))
			ft_print_error();
		top->stk_a = create_stack_a(top->stk_a, top->spl[i]);
		top->stk_a->flag = 0;
		if (top->stk_a == NULL)
		{
			free_tab_without_index(top->spl);
			return (-1);
		}
		top->len_a++;
	}
	return (0);
}
