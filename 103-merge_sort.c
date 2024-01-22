#include "sort.h"

void merge_subar(int *subar, int *buff, size_t front, size_t mid,
		size_t back);
void merge_sort_recur(int *subar, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * merge_subar - Func sorting a subarray of ints.
 * @subar: The subarray of an array of ints to sort.
 * @buff: storage beuffer of the sorted subarray.
 * @front: The front ind of the array.
 * @mid: The middle ind of the array.
 * @back: The back ind of the array.
 */

void merge_subar(int *subar, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t m, n, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subar + front, mid - front);

	printf("[right]: ");
	print_array(subar + mid, back - mid);

	for (m = front, n = mid; m < mid && n < back; k++)
		buff[k] = (subar[m] < subar[n]) ? subar[m++] : subar[n++];
	for (; m < mid; m++)
		buff[k++] = subar[m];
	for (; n < back; n++)
		buff[k++] = subar[n];
	for (m = front, k = 0; m < back; m++)
		subar[m] = buff[k++];

	printf("[Done]: ");
	print_array(subar + front, back - front);
}

/**
 * merge_sort_recur - Func implementing the merge sort
 * algorithm through recursion.
 * @subar: A subarray of an array of ints to sort.
 * @buff: Storage buffer for the sorted result.
 * @front: The front ind of the subarray.
 * @back: The back ind of the subarray.
 */

void merge_sort_recur(int *subar, int *buff, size_t front, size_t back)
{
	size_t midd;

	if (back - front > 1)
	{
		midd = front + (back - front) / 2;
		merge_sort_recur(subar, buff, front, midd);
		merge_sort_recur(subar, buff, midd, back);
		merge_subar(subar, buff, front, midd, back);
	}
}

/**
 * merge_sort - Sorting an array of ints in
 * ascending order using the merge sort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 * Description: Implementation of the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recur(array, buff, 0, size);

	free(buff);
}
