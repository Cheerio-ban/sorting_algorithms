#include "sort.h"
#include <stddef.h>

/**
 * bubble_sort - sort an array using bubble sort algorithm
 * @array: array to be sort
 * @size: length of the array
 * Return: Nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j;

	if (!array || !size)
		return;

	while (i < size)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int tmp = array[j];

				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}

		i++;
	}
}
