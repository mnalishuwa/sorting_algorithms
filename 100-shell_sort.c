#include "sort.h"

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

/**
 * shell_sort - shell sort implementation
 * Description: knuth sequence shell sort implementation
 *
 * @array: pointer to int array
 * @size: size of array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int i, j, k, hk, n;

	if (array == NULL)
		return;

	n = size;
	k = log(n + 1) / log(3); /* find knuth number >= size/2 */

	for (; k >= 1; k--)
	{
		hk = (pow(3, k) - 1) / 2; /* compute step size */

		for (i = hk; i < n; i++)
		{
			for (j = i; (j >= hk) && (array[j - hk] > array[j]); j -= hk)
			{
				swap_ints(&array[j - hk], &array[j]);
			}
		}
		print_array(array, size);
	}
}
