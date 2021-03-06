/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:51:51 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/09 20:55:46 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	display_actions(void (*action)(), char *operation_str, t_stk *top)
{
	if (action == &ra || action == &rra || action == &sa)
		action(&top->stk_a);
	else if (action == &rb || action == &rrb || action == &sb)
		action(&top->stk_b);
	else if (action == &p_rrotate || action == &p_rrev_rotate
		|| action == &p_sswap || action == &pa || action == &pb)
		action(&top->stk_a, &top->stk_b);
	ft_printf("%s", operation_str);
}
