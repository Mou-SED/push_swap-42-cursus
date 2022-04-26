/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:50:09 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/25 23:33:41 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

int	partition(int arr[], int lower, int upper)
{
	int i = (lower - 1);

	int pivot = arr[upper];

	int j;
	for (j = lower; j < upper; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[upper]);
	return (i + 1);
}

void	quicksort(int arr[], int lower, int upper)
{
	if (upper > lower)
	{
		int partitionIndex = partition(arr, lower, upper);
		quicksort(arr, lower, partitionIndex - 1);
		quicksort(arr, partitionIndex + 1, upper);
	}
}

int	*content_of_next(t_stk *top)
{
	int			i;
	t_d_list	*tmp;
	int			*array;
	
	array = malloc(sizeof(int) * top->len_a);
	if (array == NULL)
		return (NULL);
	i = 0;
	tmp = top->stk_a;
	while (tmp)
	{
		array[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	quicksort(array, 0, top->len_a - 1);
	return (array);
}
