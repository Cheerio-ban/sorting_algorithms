<<<<<<< HEAD
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

=======
#include "sort.h"
#include <stddef.h>



void shell_sort(int *arr, size_t size)
{
	size_t gap;

	for (gap = size / 2; gap > 0; gap /= 2)
	{
		size_t i = gap;

		while (i < size)
		{
			size_t j = i;
			int tmp = arr[i];

			while (j >= gap && arr[j - gap] > tmp)
			{
				arr[j] = arr[j - gap];

				j -= gap;
			}

			arr[j] = tmp;
			print_array(arr, size);

			i++;
		}
	}
}
>>>>>>> dae4f38 (Added the rightful time complexity for bubble sort)
