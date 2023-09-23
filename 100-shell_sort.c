#include "sort.h"

/**
 * swap - Swap two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using Shell Sort
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
	{
		gap = gap * 3 + 1;
	}
	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
