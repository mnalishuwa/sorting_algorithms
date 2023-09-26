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
	sort(array, 1, size - 1);
}

/**
 * partition - returns the pivot element
 * Description: returns pivot idx given array size
 *
 * @array: int array pointer
 * @hi: int size
 * @lo: int lo
 *
 * Return: size_t, pivot
 */
size_t partition(int *array, size_t lo, size_t hi)
{
	int pivot_element;
	size_t idx, j_idx;

	pivot_element = array[hi];
	idx = lo - 1;

	for (j_idx = lo; j_idx <= hi - 1; j_idx++)
	{
		if (array[j_idx] <= pivot_element)
		{
			idx += 1;
			swap_ints((array + idx), (array + j_idx));
			print_array(array, hi + 1);
		}
	}
	swap_ints((array + idx + 1), (array + hi));
	print_array(array, hi + 1);
	return (idx + 1);
}

/**
 * sort - qsort implementation
 * Description: quicksort implementation
 *
 * @array: int array
 * @hi: int
 * @lo: int
 *
 * Return: void
 */
void sort(int *array, size_t lo, size_t hi)
{
	size_t pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi);
		sort(array, lo, pivot - 1);
		sort(array, pivot + 1, hi);
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
void swap_ints(int *x, int *y)
{
	if (x != y)
	{
		*x = *x ^ *y;
		*y = *x ^ *y;
		*x = *x ^ *y;
	}
}
