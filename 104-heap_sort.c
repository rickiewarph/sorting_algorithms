#include "sort.h"

void qwap_ints(int *a, int *b);
void maxim_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * qwap_ints - Swapping two ints in an array.
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
 * maxim_heapify - Turning a bin tree into a complete bin heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The ind of the base row of the tree.
 * @root: The root node of the bin tree.
 */

void maxim_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t lft, rght, large;

	lft = 2 * root + 1;
	rght = 2 * root + 2;
	large = root;

	if (lft < base && array[lft] > array[large])
		large = lft;
	if (rght < base && array[rght] > array[large])
		large = rght;

	if (large != root)
	{
		qwap_ints(array + root, array + large);
		print_array(array, size);
		maxim_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sorting an array of int in
 * ascending order using the heap sort algorithm.
 * @array: An array of int.
 * @size: The size of the array.
 * Description: Implementing the sift-down hp sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int m;

	if (array == NULL || size < 2)
		return;

	for (m = (size / 2) - 1; m >= 0; m--)
		maxim_heapify(array, size, size, m);

	for (m = size - 1; m > 0; m--)
	{
		qwap_ints(array, array + m);
		print_array(array, size);
		maxim_heapify(array, size, m, 0);
	}
}
