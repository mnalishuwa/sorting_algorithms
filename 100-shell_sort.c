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

	if (array == NULL || size < 2)
		return;

	n = size;
	k = knuth_log(n + 1) + 1; /* find knuth number >= size/2 */

	for (; k >= 1; k--)
	{
		hk = (_pow_recursion(3, k) - 1) / 2; /* compute step size */

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

/**
 * _pow_recursion - return x ^ y
 * Description: receives ints x, y and compute x^y
 *
 * @x: int arg 1
 * @y: int arg 2
 *
 * Return: int, x^y
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	else if (y == 0)
		return (1);
	else
		return (x * _pow_recursion(x, y - 1));
}

/**
 * knuth_log - approximates the natural log of a given value
 * Description: uses the Taylor Series to approximate
 * natural log of a value
 *
 * @x: input value
 *
 * Return: double, natural log
 */
size_t knuth_log(size_t x)
{
	size_t n = 0;

	if (x < 3)
		return (1);

	while (x >= 3)
	{
		x = x / 3;
		n++;
	}

	return (n);
}
