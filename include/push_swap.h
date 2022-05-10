/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:53:24 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/10 16:21:15 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/include/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"

# include <stdlib.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

// Doubly linked list struct
typedef struct s_d_list
{
	int				flag;
	struct s_d_list	*prev;
	int				content;
	struct s_d_list	*next;
}	t_d_list;

// Main struct
typedef struct s_stk
{
	t_d_list	*stk_a;
	t_d_list	*stk_b;
	char		**spl;
	int			pivot;
	int			len_a;
	int			len_b;
	int			next_one;
	int			next_to_sort;
	int			first_sort;
	int			*sorted_array;
}	t_stk;

// Doubly linked list prototype
t_d_list	*ft_d_lstnew(int content);
void		ft_d_lstadd_front(t_d_list **alst, t_d_list *new);
void		ft_d_lstadd_back(t_d_list **alst, t_d_list *new);
t_d_list	*ft_d_lstlast(t_d_list *lst);
void		ft_d_lstdelone(t_d_list *lst, void (*del) (void *));
void		ft_d_lstclear(t_d_list **lst, void (*del)(void *));

// Libft functions prototype
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const	char	*s);
int			ft_atoi(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s1);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);

// Utils functions prototype
int			is_plus_or_minus(int c);
int			is_space(int c);
char		*ft_strjoin_char(char *s1, char const *s2, char c);
char		**join_args(char **str);
long long	ft_atoi_long(const char *str);
int			check_error(char *str);
int			check_error_overflow(char *str);
void		check_dupl_args(char **str);
int			ft_strcmp(char *s1, char *s2);
void		ft_print_error(void);
void		free_tab_without_index(char **tab);

// Sorting functions
int			len_div_2(t_d_list *dupl_stk, int len);
int			check_mid(t_d_list *top, int mid, char c);
int			find_mid(t_stk *top, int len, char stack_name);
void		begin_sort(t_stk *top);
void		part1_sort(t_stk *top);
void		part2_sort(t_stk *top);
void		quick_sort_b(t_stk *top);
void		main_sorting(t_stk *top, int value);
void		sorting_three_numbers(t_stk *top);
void		sorting_four_numbers(t_stk *top);
void		sorting_five_numbers(t_stk *top);
void		choise_rotate_or_revrotate(t_stk *top, int len);
void		move_next_to_sort(t_stk *top);
void		push_next_sort_a(t_stk *top);

// Stack functions
t_d_list	*create_stack_a(t_d_list *top_a, char *str);
t_d_list	*duplicate_stack(t_d_list *top, int len);
t_d_list	*sort_duplicate_stack(t_d_list *dupl_stk);
int			ft_create_stack(t_stk *top, char **av);
int			is_sorted(t_d_list *p_stack);
int			is_empty(t_d_list *p_stack);
int			len_stk(t_d_list stk_a);
int			len_stack_by_flag(t_d_list *top, int flag);

// Actions functions prototype
void		p_push(t_d_list **top_to_get, t_d_list **top_to_add);
void		pa(t_d_list **top_a, t_d_list **top_b);
void		pb(t_d_list **top_a, t_d_list **top_b);
void		p_swap(t_d_list **top);
void		sa(t_d_list **top_a);
void		sb(t_d_list **top_b);
void		p_sswap(t_d_list **top_a, t_d_list **top_b);
void		p_rotate(t_d_list **top);
void		ra(t_d_list **top_a);
void		rb(t_d_list **top_b);
void		p_rrotate(t_d_list **top_a, t_d_list **top_b);
void		p_rev_rotate(t_d_list **top);
void		rra(t_d_list **top_a);
void		rrb(t_d_list **top_b);
void		p_rrev_rotate(t_d_list **top_a, t_d_list **top_b);
void		display_actions(void (*action)(), char *operation_str, t_stk *top);

// Normal quickSort Algorithm for sorting the array
int			*content_of_next(t_stk *top);
void		quicksort(int arr[], int lower, int upper);
int			partition(int arr[], int lower, int upper);
void		swap(int *first, int *second);

#endif
