#include <stdio.h>
#include "sort.h"

void print_my_array(char *s, const int *array, size_t low, size_t high);
void merge_divide(int *array, size_t low, size_t high, int *new_array);
void merge_conquer(int *array, size_t low,
		   size_t middle, size_t high, int *new_array);

/**
 * print_my_array - Prints an array of integers within constrained indexes
 * @s: String appended
 * @array: The array to be printed
 * @low: lower boundary
 * @high: upper boundary
 */

void print_my_array(char *s, const int *array, size_t low, size_t high)
{
	size_t i;

	printf("[%s]: ", s);
	i = low;
	while (array && i <= high)
	{
		if (i > low)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}


/**
 * merge_divide - implements merge sort
 * divides and conquer technique
 * @array: given array
 * @low: lower boundary
 * @high: upper boundary
 * @new_array: new_array array
 */
void merge_divide(int *array, size_t low, size_t high, int *new_array)
{
	size_t middle;

	if (low >= high)
		return;

	middle = (high + low - 1) / 2;

	merge_divide(array, low, middle, new_array);
	merge_divide(array, middle + 1, high, new_array);
	merge_conquer(array, low, middle, high, new_array);
}

/**
 * merge_conquer - merges two sub arrays
 * @array: given array
 * @low: lower boundary
 * @middle: lower exclusive separator
 * @high: upper boundary
 * @new_array: new_array array
 */
void merge_conquer(int *array, size_t low,
		   size_t middle, size_t high, int *new_array)
{
	size_t first, second, third, i;

	printf("Merging...\n");
	print_my_array("left", array, low, middle);
	print_my_array("right", array, middle + 1, high);

	first = third = low;
	second = middle + 1;
	while (first <= middle && second <= high)
	{
		if (array[first] <= array[second])
			new_array[third++] = array[first++];
		else
			new_array[third++] = array[second++];
	}

	while (first <= middle)
		new_array[third++] = array[first++];

	while (second <= high)
		new_array[third++] = array[second++];

	for (i = low; i <= high; i++)
		array[i] = new_array[i];

	print_my_array("Done", new_array, low, high);
}

/**
 * merge_sort - sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: given array
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *new_array;

	if (!array || size < 2)
		return;

	new_array = malloc(sizeof(int) * size);
	if (!new_array)
		return;

	merge_divide(array, 0, size - 1, new_array);
	free(new_array);
}
