#include "sort.h"

/**
 * selection_sort - sorts an array of integers
 * Description: function to sort an array of integers
 * using the selection sort algorithm
 *
 * @array: int array
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t idx, smallest_idx, unsrtd_idx;

	for (idx = 0; idx < size; idx++)
	{
		smallest_idx = idx;
		for (unsrtd_idx = idx; unsrtd_idx < size; unsrtd_idx++)
		{
			if (*(array + unsrtd_idx) < *(array + smallest_idx))
			{
				smallest_idx = unsrtd_idx;
			}
		}
		swap_ints((array + idx), (array + smallest_idx));
		if (idx != smallest_idx)
			print_array(array, size);
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
