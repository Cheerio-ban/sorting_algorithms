#include "sort.h"
#include <stddef.h>

void qs(int *arr, int lo, int hi);
int prtn(int *arr, int lo, int hi);

/**
 * quick_sort - sort an array using quick sort algorithm
 * @arr: array to be sorted
 * @size: length of the array
 * Return: Nothing
 */

void quick_sort(int *arr, size_t size)
{
	qs(arr, 0, size - 1);
}


/**
 * prtn - partition the array
 * @arr: array to be partition
 * @lo: the lower bond
 * @hi: the upper bond
 * Return: index of the pivot
 */

int prtn(int *arr, int lo, int hi)
{
	int pvt = arr[hi], tmp;
	int idx = lo - 1;
	int i;

	for (i = lo; i <= hi - 1; i++)
	{
		if (arr[i] <= pvt)
		{

			idx++;
			tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
			print_array(arr, hi);
		}
	}

	idx++;
	arr[hi] = arr[idx];
	arr[idx] = pvt;
	print_array(arr, hi);

	return (idx);
}


/**
 * qs - do the recursive call
 * @arr: array to be sorted
 * @lo: the lower bond
 * @hi: the upper bond
 * Return: Nothing
 */
void qs(int *arr, int lo, int hi)
{
	int pidx;

	if (lo >= hi)
		return;

	pidx = prtn(arr, lo, hi);

	qs(arr, lo, pidx - 1);
	qs(arr, pidx + 1, hi);
}
