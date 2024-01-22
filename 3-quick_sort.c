#include "sort.h"

void qwap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int lft, int rght);
void lomuto_sort(int *array, size_t size, int lft, int rght);
void quick_sort(int *array, size_t size);

/**
 * qwap_ints -FUnc to swap two int in an array.
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
 * lomuto_partition - Func to command a subset of an array of ints
 * as per lomuto partition scheme (last element as pivot).
 * @array: The array of ints.
 * @size: The size of the array.
 * @lft: The starting ind of the subset to order.
 * @rght: The ending ind of the subset to order.
 *
 * Return: The final partition ind.
 */

int lomuto_partition(int *array, size_t size, int lft, int rght)
{
	int *pvot, abve, blow;

	pvot = array + rght;
	for (abve = blow = lft; blow < rght; blow++)
	{
		if (array[blow] < *pvot)
		{
			if (abve < blow)
			{
				qwap_ints(array + blow, array + abve);
				print_array(array, size);
			}
			abve++;
		}
	}

	if (array[abve] > *pvot)
	{
		qwap_ints(array + abve, pvot);
		print_array(array, size);
	}

	return (abve);
}

/**
 * lomuto_sort - Func to implement the quicksort
 * algorithm through recursion.
 * @array: An array of ints to sort.
 * @size: The array size.
 * @lft: The starting ind of the array partition to be ordered.
 * @rght: The ending index of the array partition to be ordered.
 *
 * Description: Uses the Lomuto partition scheme.
 */

void lomuto_sort(int *array, size_t size, int lft, int rght)
{
	int prt;

	if (rght - lft > 0)
	{
		prt = lomuto_partition(array, size, lft, rght);
		lomuto_sort(array, size, lft, prt - 1);
		lomuto_sort(array, size, prt + 1, rght);
	}
}

/**
 * quick_sort - Func to sort an array of int in
 * ascending order with the use of the quicksort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 *
 * Description: Apply the Lomuto partition scheme to
 * print the array after each swap of two elements.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
