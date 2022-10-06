#include <stdio.h>
#include "sort.h"
/**
 * shell_sort - Sorts an array using the shell sort algorithm
 * @array: Array to be sorted
 * @size: Size of array to be sorted
 */

void shell_sort(int *array, size_t size)
{
	int gap, i, temp;

	for (gap = size/2; gap > 0; gap /= 2)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			int j;

			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
		}

