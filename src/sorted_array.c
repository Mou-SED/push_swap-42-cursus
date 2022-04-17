/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:50:09 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/14 13:58:57 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Swap function to swap two values
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

/*Partition method which selects a pivot
  and places each element which is less than the pivot value to its left
  and the elements greater than the pivot value to its right
  arr[] --- array to be partitioned
  lower --- lower index
  upper --- upper index
*/
int partition(int arr[], int lower, int upper)
{
    int i = (lower - 1);

    int pivot = arr[upper];  // Selects last element as the pivot value

    int j;
    for (j = lower; j < upper; j++)
    {
        if (arr[j] <= pivot)
        {  // if current element is smaller than the pivot

            i++;  // increment the index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[upper]);  // places the last element i.e, the pivot
                                     // to its correct position

    return (i + 1);
}

/*This is where the sorting of the array takes place
    arr[] --- Array to be sorted
    lower --- Starting index
    upper --- Ending index
*/
void quicksort(int arr[], int lower, int upper)
{
    if (upper > lower)
    {
        // partitioning index is returned by the partition method , partition
        // element is at its correct poition

        int partitionIndex = partition(arr, lower, upper);

        // Sorting elements before and after the partition index
        quicksort(arr, lower, partitionIndex - 1);
        quicksort(arr, partitionIndex + 1, upper);
    }
}

int *content_of_next(t_stk *top)
{
    int *array;
    int i;
    t_d_list *tmp;
    
    array = malloc(sizeof(int) * top->len);
    i = 0;
    tmp = top->stk_a;
    while (tmp)
    {
        array[i] = tmp->content;
        i++;
        tmp = tmp->next;
    }
    quicksort(array, 0, top->len - 1);
    return (array);
}