/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 02:38:57 by moseddik           #+#    #+#             */
/*   Updated: 2022/02/28 02:39:09 by moseddik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/include/libft.h"

#include <stdlib.h>
#include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct stack_info
{
    int *data;
}   stack_info;

typedef struct s_stk
{
    t_d_list *stk_a;
    t_d_list *stk_b;
    int len;
    int index;
    char **spl;
}       p_stk;


int         is_plus_or_minus(int c);

int         is_space(int c);

char        *ft_strjoin_char(char *s1, char const *s2, char c);

char        **join_args(char **str);

long long   ft_atoi_long(const char *str);

int         check_error(char *str);

int         check_error_overflow(char *str);

void        check_dupl_args(char **str);

int	        ft_strcmp(char *s1,char *s2);

int         is_sorted(t_d_list *p_stack);

int         is_empty(t_d_list *p_stack);

void        push_a_b(t_d_list **top_to_get, t_d_list **top_to_add);

void        p_swap(t_d_list **top);

void	    p_sswap(t_d_list **top_a, t_d_list **top_b);

void        p_rotate(t_d_list **top);

void        p_rrotate(t_d_list **top_a, t_d_list **top_b);

void        p_rev_rotate(t_d_list **top);

void        p_rrev_rotate(t_d_list **top_a, t_d_list **top_b);

#endif