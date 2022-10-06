#include <stdio.h>
#include "sort.h"
#include <stddef.h>

/**
 * selection_sort - sorts an array using the selection sort method
 * @array: Array to be sorted
 * @size: Size of array to be sorted
 *
 * Return: Nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, idx;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		if (idx == i)
			continue;
		tmp = array[i];
		array[i] = array[idx];
		array[idx] = tmp;
		print_array(array, size);
	}
}
