#include "sort.h"

/**
 * get_maxim - Func to get the max value in an array of integers.
 * @array: An array of ints.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
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
 * counting_sort - FUnc sorting an array of ints in ascennsion
 * using the counting sort algorithm.
 * @array: An array of ints.
 * @size: The size of the array.
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *sorted, maxim, m;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	maxim = get_maxim(array, size);
	counter = malloc(sizeof(int) * (maxim + 1));
	if (counter == NULL)
	{
		free(sorted);
		return;
	}

	for (m = 0; m < (maxim + 1); m++)
		counter[m] = 0;
	for (m = 0; m < (int)size; m++)
		counter[array[m]] += 1;
	for (m = 0; m < (maxim + 1); m++)
		counter[m] += counter[m - 1];
	print_array(counter, maxim + 1);

	for (m = 0; m < (int)size; m++)
	{
		sorted[counter[array[m]] - 1] = array[m];
		counter[array[m]] -= 1;
	}

	for (m = 0; m < (int)size; m++)
		array[m] = sorted[m];

	free(sorted);
	free(counter);
}
