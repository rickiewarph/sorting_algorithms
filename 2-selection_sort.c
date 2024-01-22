#include "sort.h"

/**
 * qwap_ints -Fuunc to swap two ints in an array.
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
 * selection_sort -Func to sort an array of integers in ascending order
 * with the use of the selection sort algorithm.
 * @array: An array of int.
 * @size: The size of the array.
 *
 * Description: Printing the array after each swap.
 */

void selection_sort(int *array, size_t size)
{
	int *minim;
	size_t m, n;

	if (array == NULL || size < 2)
		return;

	for (m = 0; m < size - 1; m++)
	{
		minim = array + m;
		for (n = m + 1; n < size; n++)
			minim = (array[n] < *minim) ? (array + n) : minim;

		if ((array + m) != minim)
		{
			qwap_ints(array + m, minim);
			print_array(array, size);
		}
	}
}
