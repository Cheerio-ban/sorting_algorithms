#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array using the counting sort algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted
 *
 * Return: Nothing
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int *counting_array, *final_array, j, max;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	final_array = malloc(sizeof(int) * size);
	if (!final_array)
		return;

	counting_array = malloc(sizeof(int) * (max + 1));
	if (!counting_array)
		return;

	for (j = 0; j < (max + 1); j++)
		counting_array[j] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	for (j = 1; j <= max; j++)
	{
		counting_array[j] += counting_array[j - 1];
	}
	print_array(counting_array, max + 1);
	for (i = 0; i < size; i++)
	{
		printf("final array: %d , counting array: %d, array[i] is: %d \n", final_array[counting_array[array[i]] - 1],counting_array[array[i]] ,array[i]);
		final_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = final_array[i];
	free(counting_array);
	free(final_array);
}
