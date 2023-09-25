#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of the elements in the array
 */
void counting_sort(int *array, size_t size)
{
	int max = 0;
	int *count_array = NULL;
	int *sorted_array = malloc(sizeof(int) * size);
	size_t i;

	if (!sorted_array)
		return;
	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count_array = malloc(sizeof(int) * (max + 1));
	if (!count_array)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i <= (size_t)max; i++)
		count_array[i] = 0;
	for (i = 0; i < size; i++)
		count_array[array[i]]++;
	for (i = 1; i <= (size_t)max; i++)
		count_array[i] += count_array[i - 1];
	print_array(count_array, max + 1);

	for (i = 0; i < size; i++)
	{
		sorted_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];
	free(sorted_array);
	free(count_array);
}
