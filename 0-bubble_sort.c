#include "sort.h"

/**
 * qwap_ints - Func to swap 2 ints in an array.
 * @a: The 1st int to swap.
 * @b: The 2nd int to swap.
 */

void qwap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Func sorting an array of int in ascending order.
 * @array: An array of int to sort.
 * @size: The size of array.
 * Description: Printing array after each swap.
 */

void bubble_sort(int *array, size_t size)
{
	size_t m, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (m = 0; m < len - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				qwap_ints(array + m, array + m + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
