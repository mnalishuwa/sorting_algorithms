#include "sort.h"

/**
 * bubble_sort - sorts an array of ints
 * Description: sorts an array of integers using the
 * Bubble Sort algorithm.
 *
 * @array: pointer to the first element of the array
 * @size: int size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx, swapped, array_size = size;

	for (swapped = 1; swapped;)
	{
		swapped = 0;

		for (idx = 1; idx < size; idx++)
		{
			if (*(array + idx - 1) > *(array + idx))
			{
				swap_ints((array + idx - 1), (array + idx));
				print_array(array, array_size);
				swapped = 1;
			}
		}
		size -= 1;
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
