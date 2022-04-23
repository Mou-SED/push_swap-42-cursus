/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:00:45 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/23 03:02:39 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// //! indexing function
// int ft_indexing(t_d_list *top)
// {
// 	int	i;

// 	i = 0;
// 	while (top)
// 	{
// 		top->index = i;
// 		i++;
// 		top = top->next;
// 	}
// 	return (0);
// }

// //! find element by index
// t_d_list *find_element_by_index(t_d_list *top, int index)
// {
// 	while (top->index != index)
// 		top = top->next;
// 	return top;
// }

//? **********************************************************************************************/

int main(int ac, char **av)
{
	t_stk	top;
	int		i;
	
	ft_bzero(&top, sizeof(top));
	if (ac > 1)
	{
		top.stk_b = NULL;
		i = 0;
		top.len_a = 0;
		top.spl = join_args(av);
		check_dupl_args(top.spl);
		while (top.spl[++i])
		{
			if (check_error(top.spl[i]) || check_error_overflow(top.spl[i]))
				ft_print_error();
			top.stk_a = create_stack_a(top.stk_a, top.spl[i]);
			top.len_a++;
		}
		
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
		if (ac == 4)
			sorting_3(&top);
		else if (ac > 4)
		{
			quick_sort(&top, &(top.next_one), top.sorted_array, 0);
			quick_sort(&top, &(top.next_one), top.sorted_array, 1);
		}
		
		
		//! * *************************************************************** */
		//! *                                                                 */
		//! *						         After Sorting...				  */
		//! *																  */
		//! * *************************************************************** */
		
		ft_printf("--------------------AFTER--------------------\n");
		ft_stack_print(top.stk_a, "Stack A");
		ft_stack_print(top.stk_b, "Stack B");
		printf("this is the value of our next_to_sort:%d\n", top.next_to_sort);
	}
	return (0);
}
