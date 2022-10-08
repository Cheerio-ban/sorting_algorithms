#include <stdio.h>
#include "sort.h"
/**
 * merge_sort - sorts an array using the merge sort algorithm
 * @array: Array of ints to be sorted
 * @size: Size of array to be sorted
 *
 * Return: None
 */

void merge(int *array, int *left, int *right, size_t nL, size_t nR);

void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t mid, i;

	if (size < 2)
		return;
	mid = size / 2;
	left = malloc(sizeof(int) * mid);
	right = malloc(sizeof(int) * (size - mid));
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = size - mid; i < size; i++)
		right[i - mid] = array[i];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, left, right, mid, size - mid);
}

void merge(int *array, int *left, int *right, size_t nL, size_t nR)
{
	size_t i, j, k;

	i = 0;
	j = 0;
	k  = 0;
	while (i < nL && j < nR)
	{
		if (left[i] <= right[j])
		{
			array[k] = left[i];
			k++;
			i++;
		}
		else
		{
			array[k] = right[j];
			k++;
			j++;
		}
	}
	while (i < nL)
	{
		array[k] = left[i];
		i++;
		k++;
	}
	while (j < nR)
	{
		array[k] = right[j];
		j++;
		k++;
	}
	printf("Left: ");
	print_array(left, nL);
	printf("right: ");
	print_array(right, nR);
	free(left);
	free(right);
}

