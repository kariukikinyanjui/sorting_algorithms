#include "sort.h"

/**
 * swap = Swap two integers in an array
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
 * lomuto_partition - Order a subset of an array of integers according to the
 * Lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @size: The size of the array.
 * @start: The starting index of the subset to order.
 * @end: The ending index of the subset to order.
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int high, int low)
{
	int *pivot, i, j;

	pivot = array + low;

	for (i = j = high; j < low; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}
	return (i);
}

/**
 * quicksort - Implement the quicksort algorithm through recursion
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @start: The starting index of the array partition to order.
 * @end: The ending index of the array partition to order.
 */
void quicksort(int *array, size_t size, int start, int end)
{
	int part;

	if (end - start > 0)
	{
		part = lomuto_partition(array, size, start, end);
		quicksort(array, size, start, part - 1);
		quicksort(array, size, end, part + 1);
	}
}

/**
 * quick_sort - sort an array of integers in ascending order using the
 * quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, size, 0, size - 1);
}
