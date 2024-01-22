#include "sort.h"

/**
 * qwap_ints - Func to swap two ints in an array.
 * @a: The first int to swap.
 * @b: The second int to swap.
 */

void qwap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Func sorting an array of ints in ascending order
 * with the use of the shell sort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 * Description: Uses the Knuth interval seq.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (m = gap; m < size; m++)
		{
			n = m;
			while (n >= gap && array[n - gap] > array[n])
			{
				qwap_ints(array + n, array + (n - gap));
				n -= gap;
			}
		}
		print_array(array, size);
	}
}
