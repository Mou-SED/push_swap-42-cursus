/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:35:08 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/10 12:06:51 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	check_dupl_numbers(t_stk *top)
{
	t_d_list	*tmp;
	t_d_list	*tmp2;

	tmp = top->stk_a;
	while (tmp != NULL)
	{
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			if (tmp->content == tmp2->content)
			{
				free_tab_without_index(top->spl);
				ft_d_lstclear(&top->stk_a, &free);
				ft_print_error();
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

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
		{
			free_tab_without_index(top->spl);
			ft_d_lstclear(&top->stk_a, &free);
			ft_print_error();
		}
		top->stk_a = create_stack_a(top->stk_a, top->spl[i]);
		top->stk_a->flag = 0;
		if (top->stk_a == NULL)
			return (free_tab_without_index(top->spl), -1);
		top->len_a++;
	}
	check_dupl_numbers(top);
	return (0);
}
