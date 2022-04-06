/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 19:00:45 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/06 17:18:25 by moseddik         ###   ########.fr       */
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
	p_stk	top;
	int		i;
	
	if (ac > 1)
	{
		top.stk_b = NULL;
		i = 0;
		top.spl = join_args(av);
		check_dupl_args(top.spl);
		while (top.spl[++i])
		{
			if (check_error(top.spl[i]) || check_error_overflow(top.spl[i]))
				ft_print_error();
			top.stk_a = create_stack_a(top.stk_a, top.spl[i]);
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
		
		// int mid;
		// top.len_by_flag = len_stack_by_flag(top.stk_a, top.stk_a->flag);
		// mid = find_mid(*top.stk_a, len_stack_by_flag(top.stk_a, top.stk_a->flag));
		
		// t_d_list *tmp;
		// tmp = top.stk_a;
		// while(tmp && top.len_by_flag)
		// {
		// 	if (tmp->flag != 0)
		// 		tmp = tmp->next;
		// 	else
		// 	{
		// 		if (tmp->content <= mid)
		// 			PB;
		// 		else
		// 			RA;
		// 		if(top.stk_b->next && top.stk_b->content < top.stk_b->next->content)
		// 			SB;
		// 		if(!check_mid(tmp, mid))
		// 			break ;
		// 		tmp = tmp->next;
		// 	}
		// 	--top.len_by_flag;
		// }
		
		
		
		// //! *********************************************************
		
		// if (top.stk_b)
		// 	mid = find_mid(*top.stk_b, len_stk(*top.stk_b));
		// while(top.stk_b)
		// {
		// 	while(top.stk_b->content != get_min_number(*top.stk_b))
		// 		stk_normalize(&top.stk_b, len_stk(*top.stk_b));
		// 	if(top.stk_b->content == get_min_number(*top.stk_b))
		// 	{
		// 		top.stk_b->flag++;
		// 		PA;
		// 		RA;
		// 	}
		// }
		
		// //! *********************************************************
		
		// mid = find_mid(*top.stk_a, len_stack_by_flag(top.stk_a, top.stk_a->flag));

		// tmp = top.stk_a;
		// top.len_by_flag = len_stack_by_flag(top.stk_a, top.stk_a->flag);
		// while(tmp && top.len_by_flag)
		// {
		// 	if (tmp->flag != 0)
		// 		tmp = tmp->next;
		// 	else
		// 	{
		// 		if (tmp->content <= mid)
		// 			PB;
		// 		else
		// 			RA;
		// 		if(top.stk_b && top.stk_b->next && top.stk_b->content < top.stk_b->next->content)
		// 			SB;
		// 		if(!check_mid(tmp, mid))
		// 			break ;
		// 		tmp = tmp->next;
		// 	}
		// 	--top.len_by_flag;
		// }
		
		// tmp = top.stk_a;
		// while(tmp)
		// {
		// 	while (tmp->flag == 0)
		// 	{
		// 		tmp = ft_d_lstlast(tmp);
		// 		tmp = tmp->prev;
		// 		RRA;
		// 	}
		// 	tmp = tmp->next;
		// }
		
		// //! *********************************************************
		// // if (top.stk_b)
		// // 	mid = find_mid(*top.stk_b, len_stk(*top.stk_b));

		// while(top.stk_b)
		// {
		// 	while(top.stk_b->content != get_min_number(*top.stk_b))
		// 		stk_normalize(&top.stk_b, len_stk(*top.stk_b));
		// 	if(top.stk_b->content == get_min_number(*top.stk_b))
		// 	{
		// 		top.stk_b->flag++;
		// 		PA;
		// 		RA;
		// 	}
		// }

		// //! *********************************************************

		// mid = find_mid(*top.stk_a, len_stack_by_flag(top.stk_a, top.stk_a->flag));

		// tmp = top.stk_a;
		// top.len_by_flag = len_stack_by_flag(top.stk_a, top.stk_a->flag);
		// while(tmp && top.len_by_flag)
		// {
		// 	if (tmp->flag != 0)
		// 		tmp = tmp->next;
		// 	else
		// 	{
		// 		if (tmp->content <= mid)
		// 			PB;
		// 		else
		// 			RA;
		// 		if(top.stk_b && top.stk_b->next && top.stk_b->content < top.stk_b->next->content)
		// 			SB;
		// 		if(!check_mid(tmp, mid))
		// 			break ;
		// 		tmp = tmp->next;
		// 	}
		// 	--top.len_by_flag;
		// }

		// tmp = top.stk_a;
		// while(tmp)
		// {
		// 	while (tmp->flag == 0)
		// 	{
		// 		tmp = ft_d_lstlast(tmp);
		// 		tmp = tmp->prev;
		// 		RRA;
		// 	}
		// 	tmp = tmp->next;
		// }
		
		// //! *********************************************************
		// if (top.stk_b)
		// 	mid = find_mid(*top.stk_b, len_stk(*top.stk_b));

		// while(top.stk_b)
		// {
		// 	while(top.stk_b->content != get_min_number(*top.stk_b))
		// 		stk_normalize(&top.stk_b, len_stk(*top.stk_b));
		// 	if(top.stk_b->content == get_min_number(*top.stk_b))
		// 	{
		// 		top.stk_b->flag++;
		// 		PA;
		// 		RA;
		// 	}
		// }

		// //! *********************************************************

		// mid = find_mid(*top.stk_a, len_stack_by_flag(top.stk_a, top.stk_a->flag));

		// tmp = top.stk_a;
		// top.len_by_flag = len_stack_by_flag(top.stk_a, top.stk_a->flag);
		// while(tmp && top.len_by_flag)
		// {
		// 	if (tmp->flag != 0)
		// 		tmp = tmp->next;
		// 	else
		// 	{
		// 		if (tmp->content <= mid)
		// 			PB;
		// 		else
		// 			RA;
		// 		if(top.stk_b && top.stk_b->next && top.stk_b->content < top.stk_b->next->content)
		// 			SB;
		// 		if(!check_mid(tmp, mid))
		// 			break ;
		// 		tmp = tmp->next;
		// 	}
		// 	--top.len_by_flag;
		// }

		// tmp = top.stk_a;
		// while(tmp)
		// {
		// 	while (tmp->flag == 0)
		// 	{
		// 		tmp = ft_d_lstlast(tmp);
		// 		tmp = tmp->prev;
		// 		RRA;
		// 	}
		// 	tmp = tmp->next;
		// }
		
		// //! *********************************************************
		
		// if (top.stk_b)
		// 	mid = find_mid(*top.stk_b, len_stk(*top.stk_b));

		// while(top.stk_b)
		// {
		// 	while(top.stk_b->content != get_min_number(*top.stk_b))
		// 		stk_normalize(&top.stk_b, len_stk(*top.stk_b));
		// 	if(top.stk_b->content == get_min_number(*top.stk_b))
		// 	{
		// 		top.stk_b->flag++;
		// 		PA;
		// 		RA;
		// 	}
		// }
		
		// //! *********************************************************

		// mid = find_mid(*top.stk_a, len_stack_by_flag(top.stk_a, top.stk_a->flag));

		// tmp = top.stk_a;
		// top.len_by_flag = len_stack_by_flag(top.stk_a, top.stk_a->flag);
		// while(tmp && top.len_by_flag)
		// {
		// 	if (tmp->flag != 0)
		// 		tmp = tmp->next;
		// 	else
		// 	{
		// 		if (tmp->content <= mid)
		// 			PB;
		// 		else
		// 			RA;
		// 		if(top.stk_b && top.stk_b->next && top.stk_b->content < top.stk_b->next->content)
		// 			SB;
		// 		if(!check_mid(tmp, mid))
		// 			break ;
		// 		tmp = tmp->next;
		// 	}
		// 	--top.len_by_flag;
		// }

		// tmp = top.stk_a;
		// while(tmp)
		// {
		// 	while (tmp->flag == 0)
		// 	{
		// 		tmp = ft_d_lstlast(tmp);
		// 		tmp = tmp->prev;
		// 		RRA;
		// 	}
		// 	tmp = tmp->next;
		// }

		// //! *********************************************************
		
		// if (top.stk_b)
		// 	mid = find_mid(*top.stk_b, len_stk(*top.stk_b));

		// while(top.stk_b)
		// {
		// 	while(top.stk_b->content != get_min_number(*top.stk_b))
		// 		stk_normalize(&top.stk_b, len_stk(*top.stk_b));
		// 	if(top.stk_b->content == get_min_number(*top.stk_b))
		// 	{
		// 		top.stk_b->flag++;
		// 		PA;
		// 		RA;
		// 	}
		// }
		
		// //! *********************************************************

		// mid = find_mid(*top.stk_a, len_stack_by_flag(top.stk_a, top.stk_a->flag));

		// tmp = top.stk_a;
		// top.len_by_flag = len_stack_by_flag(top.stk_a, top.stk_a->flag);
		// while(tmp && top.len_by_flag)
		// {
		// 	if (tmp->flag != 0)
		// 		tmp = tmp->next;
		// 	else
		// 	{
		// 		if (tmp->content <= mid)
		// 			PB;
		// 		else
		// 			RA;
		// 		if(top.stk_b && top.stk_b->next && top.stk_b->content < top.stk_b->next->content)
		// 			SB;
		// 		if(!check_mid(tmp, mid))
		// 			break ;
		// 		tmp = tmp->next;
		// 	}
		// 	--top.len_by_flag;
		// }

		// tmp = top.stk_a;
		// while(tmp)
		// {
		// 	while (tmp->flag == 0)
		// 	{
		// 		tmp = ft_d_lstlast(tmp);
		// 		tmp = tmp->prev;
		// 		RRA;
		// 	}
		// 	tmp = tmp->next;
		// }
		
		// //! *********************************************************
		
		// if (top.stk_b)
		// 	mid = find_mid(*top.stk_b, len_stk(*top.stk_b));

		// while(top.stk_b)
		// {
		// 	while(top.stk_b->content != get_min_number(*top.stk_b))
		// 		stk_normalize(&top.stk_b, len_stk(*top.stk_b));
		// 	if(top.stk_b->content == get_min_number(*top.stk_b))
		// 	{
		// 		top.stk_b->flag++;
		// 		PA;
		// 		RA;
		// 	}
		// }
		
		// //! *********************************************************
		
		// mid = find_mid(*top.stk_a, len_stack_by_flag(top.stk_a, top.stk_a->flag));

		// tmp = top.stk_a;
		// top.len_by_flag = len_stack_by_flag(top.stk_a, top.stk_a->flag);
		// while(tmp && top.len_by_flag)
		// {
		// 	if (tmp->flag != 0)
		// 		tmp = tmp->next;
		// 	else
		// 	{
		// 		if (tmp->content <= mid)
		// 			PB;
		// 		else
		// 			RA;
		// 		if(top.stk_b && top.stk_b->next && top.stk_b->content < top.stk_b->next->content)
		// 			SB;
		// 		if(!check_mid(tmp, mid))
		// 			break ;
		// 		tmp = tmp->next;
		// 	}
		// 	--top.len_by_flag;
		// }

		// tmp = top.stk_a;
		// while(tmp)
		// {
		// 	while (tmp->flag == 0)
		// 	{
		// 		tmp = ft_d_lstlast(tmp);
		// 		tmp = tmp->prev;
		// 		RRA;
		// 	}
		// 	tmp = tmp->next;
		// }
		
		// //! *********************************************************
		
		// if (top.stk_b)
		// 	mid = find_mid(*top.stk_b, len_stk(*top.stk_b));

		// while(top.stk_b)
		// {
		// 	while(top.stk_b->content != get_min_number(*top.stk_b))
		// 		stk_normalize(&top.stk_b, len_stk(*top.stk_b));
		// 	if(top.stk_b->content == get_min_number(*top.stk_b))
		// 	{
		// 		top.stk_b->flag++;
		// 		PA;
		// 		RA;
		// 	}
		// }
		
		// tmp = top.stk_a;
		// if (tmp && tmp->flag == 0 && tmp->next != 0)
		// {
		// 	top.stk_a->flag++;
		// 	RA;
		// }

		quick_sort(&top, 0);
		quick_sort(&top, 1);
		
		//! * *************************************************************** */
		//! *                                                                 */
		//! *						         After Sorting...				  */
		//! *																  */
		//! * *************************************************************** */

		// ft_printf("--------------------AFTER--------------------\n");
		// ft_stack_print(top.stk_a, "Stack A");
		// ft_stack_print(top.stk_b, "Stack B");
	}
	return (0);
}
