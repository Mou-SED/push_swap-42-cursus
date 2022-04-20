/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:53:24 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/20 12:15:23 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../ft_printf/ft_printf.h"

#include <stdlib.h>
#include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define SA				display_actions(sa, "sa\n", top)
# define SB				display_actions(sb, "sb\n", top)
# define SS				display_actions(p_sswap, "ss\n", top)
# define PA				display_actions(pa, "pa\n", top)
# define PB				display_actions(pb, "pb\n", top)
# define RA				display_actions(ra, "ra\n", top)
# define RB				display_actions(rb, "rb\n", top)
# define RR				display_actions(p_rrotate, "rr\n", top)
# define RRA			display_actions(rra, "rra\n", top)
# define RRB			display_actions(rrb, "rrb\n", top)
# define RRR			display_actions(p_rrev_rotate, "rrr\n", top)

// Doubly linked list struct
typedef struct s_d_list
{
    int             flag;
	struct s_d_list	*prev;
	int				content;
	struct s_d_list	*next;
}		t_d_list;

typedef struct s_stk
{
    t_d_list    *stk_a;
    t_d_list    *stk_b;
    char        *max_number;
    char        **spl;
	int         len; // Leangth A
    int         len_by_flag;
    int         next_to_sort;
    int         max_a;
    int         max_b;
    int         value_of_flag_zero;
    int         top_flag_value;
}       t_stk;

// Doubly linked list prototype
t_d_list	*ft_d_lstnew(int content);
int			ft_d_lstsize(t_d_list *lst);
void		ft_d_lstadd_front(t_d_list **alst, t_d_list *new);
void		ft_d_lstadd_back(t_d_list **alst, t_d_list *new);
t_d_list	*ft_d_lstlast(t_d_list *lst);

// Libft functions prototype
int	        ft_isdigit(int c);
static  int count_word(char const *s, char c);
static char	*ft_strcpy(char *dst, const char *src);
static void	*free_tab(char **tab, int index );
static char	**remplis(char **splitstr, char const *s, char c, int num_of_word);
char	    **ft_split(char const *s, char c);
char	    *ft_strjoin(char const *s1, char const *s2);
size_t	    ft_strlen(const	char	*s);
int	        ft_atoi(const char *str);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
char	    *ft_strdup(const char *s1);

// Utils functions prototype
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
int         ft_indexing(t_d_list *top);
int         get_max_number(t_d_list stk_a);
int         get_min_number(t_d_list stk_a);
t_d_list    *find_element_by_index(t_d_list *top, int index);
void	    ft_bzero(void *s, size_t n);
void	    *ft_calloc(size_t count, size_t size);
void	    ft_stack_print(t_d_list *stack, char *name);
void        ft_print_error();

// Sorting functions
int         len_div_2(t_d_list top, int len);
int         check_mid(t_d_list *top, int mid, char c);
int	        find_mid(t_d_list top, int len);
int         normalize(t_d_list stk_a, int len);
void        stk_normalize(t_d_list **stk_a,int len);
void        quick_sort_a(t_stk  *top);
void        quick_sort_a_2(t_stk  *top, int *next_one, int *sorted_array);
void        quick_sort_b(t_stk  *top, int *next_one, int *sorted_array);
void        normalize_b(t_stk  *top);
void        rra_nums_of_flag_zero(t_stk  *top);
void        ra_top_num(t_stk  *top);
void        quick_sort(t_stk  *top, int value);
void        sorting_3(t_stk *top);

// Stack functions
t_d_list    *create_stack_a(t_d_list *top_a, char *str);
int         len_stk(t_d_list stk_a);
t_d_list	*duplicate_stack(t_d_list *top, int len);
int         len_stack_by_flag(t_d_list *top, int flag);

// Actions functions prototype
void        p_push(t_d_list **top_to_get, t_d_list **top_to_add);
void	    pa(t_d_list **top_a, t_d_list **top_b);
void	    pb(t_d_list **top_a, t_d_list **top_b);
void        p_swap(t_d_list **top);
void	    sa(t_d_list **top_a);
void	    sb(t_d_list **top_b);
void	    p_sswap(t_d_list **top_a, t_d_list **top_b);
void        p_rotate(t_d_list **top);
void        ra(t_d_list **top_a);
void        rb(t_d_list **top_b);
void        p_rrotate(t_d_list **top_a, t_d_list **top_b);
void        p_rev_rotate(t_d_list **top);
void        rra(t_d_list **top_a);
void        rrb(t_d_list **top_b);
void        p_rrev_rotate(t_d_list **top_a, t_d_list **top_b);
void        display_actions(void (*action)(), char *operation_str, t_stk *top);


int         *content_of_next(t_stk *top);
void        quicksort(int arr[], int lower, int upper);
int         partition(int arr[], int lower, int upper);
void        swap(int *first, int *second);

#endif