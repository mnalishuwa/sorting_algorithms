#include "sort.h"

/**
 * quick_sort - sorts an array of integers
 * Description: sorts an array of ints using the
 * quicksort algorithm
 *
 * @array: int array
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array && size >= 2)
		sort(array, 0, size - 1, size);
}

/**
 * partition - returns the pivot element
 * Description: returns pivot idx given array size
 *
 * @array: int array pointer
 * @hi: int size
 * @lo: int lo
 * @size: array size
 *
 * Return: size_t, pivot
 */
size_t partition(int *array, int lo, int hi, size_t size)
{
	int pivot_element;
	int idx, j_idx, swapped;

	pivot_element = array[hi];
	idx = lo - 1;

	for (j_idx = lo; j_idx <= hi - 1; j_idx++)
	{
		if (array[j_idx] <= pivot_element)
		{
			idx++;
			swapped = swap_ints((array + idx), (array + j_idx));
			if (swapped)
				print_array(array, size);
		}
	}
	swapped = swap_ints((array + idx + 1), (array + hi));
	if (swapped)
		print_array(array, size);
	return (idx + 1);
}

/**
 * sort - qsort implementation
 * Description: quicksort implementation
 *
 * @array: int array
 * @hi: int
 * @lo: int
 * @size: array size
 *
 * Return: void
 */
void sort(int *array, int lo, int hi, size_t size)
{
	size_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		sort(array, lo, pivot - 1, size);
		sort(array, pivot + 1, hi, size);
	}
}

/**
 * swap_ints - swaps the values of two integers
 * Description: receives two int pointers and swaps
 * their values
 *
 * @x: int
 * @y: int
 *
 * Return: void
 */
int swap_ints(int *x, int *y)
{
	int swapped = 0;

	if (x != y)
	{
		*x = *x ^ *y;
		*y = *x ^ *y;
		*x = *x ^ *y;
		swapped = 1;
	}

	return (swapped);
}
