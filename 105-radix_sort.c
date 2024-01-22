#include "sort.h"

int get_maxim(int *array, int size);
void radix_count_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_maxim - Getting the max value in an array of int.
 * @array: An array of int.
 * @size: The size of the array.
 * Return: The max int in the array.
 */

int get_maxim(int *array, int size)
{
	int maxim, m;

	for (maxim = array[0], m = 1; m < size; m++)
	{
		if (array[m] > maxim)
			maxim = array[m];
	}

	return (maxim);
}

/**
 * radix_count_sort - Sorting the sig digits of an array of
 * ints in ascending order using the counting sort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 * @sig: The sig digit to sort on.
 * @buff: A buffer to store the sorted array.
 */

void radix_count_sort(int *array, size_t size, int sig, int *buff)
{
	int counter[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t m;

	for (m = 0; m < size; m++)
		counter[(array[m] / sig) % 10] += 1;

	for (m = 0; m < 10; m++)
		counter[m] += counter[m - 1];

	for (m = size - 1; (int)m >= 0; m--)
	{
		buff[counter[(array[m] / sig) % 10] - 1] = array[m];
		counter[(array[m] / sig) % 10] -= 1;
	}

	for (m = 0; m < size; m++)
		array[m] = buff[m];
}

/**
 * radix_sort - Sortin an array of ints in ascending
 * order using the radix sort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 * Description: Implements the LSD radix sort algorithm
 * and prints the array after each sig digit increase.
 */

void radix_sort(int *array, size_t size)
{
	int maxim, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	maxim = get_maxim(array, size);
	for (sig = 1; maxim / sig > 0; sig *= 10)
	{
		radix_count_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
