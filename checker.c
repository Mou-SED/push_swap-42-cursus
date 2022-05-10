/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:36:03 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/10 16:12:23 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	ft_error(char *in_str)
{
	write(2, "Error\n", 6);
	free(in_str);
	exit(1);
}

static void	ft_actions(t_stk *top, char *in_str)
{
	if (ft_strcmp(in_str, "pa\n") == 0)
		pa(&top->stk_a, &top->stk_b);
	else if (ft_strcmp(in_str, "pb\n") == 0)
		pb(&top->stk_a, &top->stk_b);
	else if (ft_strcmp(in_str, "ra\n") == 0)
		ra(&top->stk_a);
	else if (ft_strcmp(in_str, "rb\n") == 0)
		rb(&top->stk_b);
	else if (ft_strcmp(in_str, "rr\n") == 0)
		p_rrotate(&top->stk_a, &top->stk_b);
	else if (ft_strcmp(in_str, "rra\n") == 0)
		rra(&top->stk_a);
	else if (ft_strcmp(in_str, "rrb\n") == 0)
		rrb(&top->stk_b);
	else if (ft_strcmp(in_str, "rrr\n") == 0)
		p_rrev_rotate(&top->stk_a, &top->stk_b);
	else if (ft_strcmp(in_str, "sa\n") == 0)
		sa(&top->stk_a);
	else if (ft_strcmp(in_str, "sb\n") == 0)
		sb(&top->stk_b);
	else if (ft_strcmp(in_str, "ss\n") == 0)
		p_sswap(&top->stk_a, &top->stk_b);
	else
		ft_error(in_str);
}

static void	checker(t_stk *top)
{
	char	*in_str;

	while (1)
	{
		in_str = get_next_line(0);
		if (in_str == NULL)
			return ;
		ft_actions(top, in_str);
		free(in_str);
	}
}

int	main(int ac, char **av)
{
	t_stk	top;

	if (ac > 1)
	{
		if (ft_create_stack(&top, av) == -1)
			return (-1);
		checker(&top);
		if (is_sorted(top.stk_a) && top.stk_b == NULL)
			ft_printf("OK\n");
		else
		{
			ft_printf("KO\n");
			return (-1);
		}
		free_tab_without_index(top.spl);
		ft_d_lstclear(&top.stk_a, &free);
	}
	return (0);
}
