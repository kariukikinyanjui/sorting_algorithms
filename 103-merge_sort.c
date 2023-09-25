#include "sort.h"

/**
 * merge - Merges two sorted subarrays into a single sorted subarray.
 * @array: The original array containing the subarrays to be merged.
 * @left: The start index  of the left subarray.
 * @right: The end index of the right subarray.
 * @size: Size of the original array.
 */
void merge(int *array, int *left, int *right, size_t size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc(sizeof(int) * size);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size / 2);
	printf("[right]: ");
	print_array(right, size - (size / 2));

	while (i < size / 2 && j < size - (size / 2))
	{
		if (left[i] <= right[j])
		{
			temp[k] = left[i];
			i++;
		}
		else
		{
			temp[k] = right[j];
			j++;
		}
		k++;
	}
	while (i < size / 2)
	{
		temp[k] = left[i];
		i++;
		k++;
	}
	while (j < size - (size / 2))
	{
		temp[k] = right[j];
		j++;
		k++;
	}
	for (i = 0; i < size; i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array, size);
	free(temp);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm (top-down).
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t middle = size / 2;

	if (size <= 1 || array == NULL)
		return;
	left = array;
	right = array + middle;

	merge_sort(left, middle);
	merge_sort(right, size - middle);
	merge(array, left, right, size);
}
