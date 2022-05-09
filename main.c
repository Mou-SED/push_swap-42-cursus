/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:00:45 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/05 12:16:33 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int main(int ac, char **av)
{
	t_stk	top;
	
	if (ac > 1)
	{
		if (ft_create_stack(&top, av) == -1)
			return (-1);
		if (is_sorted(top.stk_a))
			return (0);
		// ft_printf("--------------------BERFORE--------------------\n");
		// ft_stack_print(top.stk_a, "Stack A");
		// ft_stack_print(top.stk_b, "Stack B");
		
		//! * *****************************************************************/
		//! *                                                                 */
		//! *						         Sorting...					      */
		//! *																  */
		//! * *****************************************************************/
		
		top.sorted_array = content_of_next(&top);
		if (top.sorted_array == NULL)
		{
			free_tab_without_index(top.spl);
			ft_d_lstclear(&top.stk_a, &free);
			return (-1);
		}
		if (ac == 4)
			sorting_3(&top);
		else if (ac > 4)
		{
			main_sorting(&top, 0);
			// while (!is_sorted(top.stk_a))
			main_sorting(&top, 1);
		}

		//! * *************************************************************** */
		//! *                                                                 */
		//! *						         After Sorting...				  */
		//! *																  */
		//! * *************************************************************** */
		
		// ft_printf("--------------------AFTER--------------------\n");
		// ft_stack_print(top.stk_a, "Stack A");
		// ft_stack_print(top.stk_b, "Stack B");
		// printf("this is the value of our next_to_sort:%d\n", top.next_to_sort);
	}
	return (0);
}
