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


/**
 * shell_sort - sort an array using shell sort algorithm with knuth sequence
 * @arr: array to be sorted
 * @size: length of the array
 * Return: Nothing
 */


void shell_sort(int *arr, size_t size)
{
	size_t gap = 1;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		size_t i = gap;

		while (i < size)
		{
			size_t j = i;

			while (j >= gap && arr[j - gap] > arr[j])
			{
				int tmp = arr[j];

				arr[j] = arr[j - gap];
				arr[j - gap] = tmp;

				j -= gap;
			}

			i++;
		}

		print_array(arr, size);
	}
}
>>>>>>> dae4f38 (Added the rightful time complexity for bubble sort)
