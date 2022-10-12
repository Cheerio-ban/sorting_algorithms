#include "sort.h"
#include <stddef.h>


/**
 * prtn - partition the array according hoare partition
 * @arr: array to be partition
 * @low: begining of the array
 * @high: end of the array
 * @size: length of the array
 * Return: the pivot index alway
 */

int prtn(int *arr, int low, int high, size_t size)
{
	int s = low, e = high, pvt = arr[high], tmp;

	while (1)
	{
		while (arr[s] < pvt)
			s++;
		while (arr[e] > pvt)
			e--;

		if (s > e)
			return (e);
		if (s == e)
			return (e - 1);

		tmp = arr[s];
		arr[s] = arr[e];
		arr[e] = tmp;
		s++;
		e--;
		print_array(arr, size);
	}

}


/**
 * qs_hoare - make the recursive call and call the partition function
 * @arr: array to be partition
 * @low: begining of the array
 * @high: end of the array
 * @size: length of the array
 * Return: Nothing
 */


void qs_hoare(int *arr, int low, int high, size_t size)
{
	int pidx;

	if (high <= low)
		return;

	pidx = prtn(arr, low, high, size);
	if (pidx > low)
		qs_hoare(arr, low, pidx, size);
	qs_hoare(arr, pidx + 1, high, size);
}



/**
 * quick_sort_hoare - sort an array using the quick sort hoare method
 * @array: array to be sorted
 * @size: length of the array
 * Return: Nothing
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (!array || !size || size < 2)
		return;
	qs_hoare(array, 0, size - 1, size);
}
