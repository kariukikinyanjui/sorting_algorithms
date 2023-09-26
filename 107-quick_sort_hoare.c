#include "sort.h"

/**
 * quick_sort_hoare - Sorts an array of integers in ascending ordr using the 
 * Quick Sort algorithm.
 * @array: The array to be sored.
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quick_sort_hoare(array, 0, size - 1, size);
}

/**
 * _quick_sort_hoare - Recursive function to perform Quick Sort
 * @array: The array to be sorted
 * @low: The lower bound of the partition
 * @high: The upper bound of the partition
 */
void _quick_sort_hoare(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);

		if (pivot > low)
			_quick_sort_hoare(array, low, pivot, size);
		_quick_sort_hoare(array, pivot + 1, high, size);
	}
}

/**
 * hoare_partition - Partitions the array for Quick Sort
 * @array: The array to be partitioned
 * @low: The lower bound of the partition
 * @high_ The upper bound of the partition
 * Return: The pivot index
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[low];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		}
		while (array[i] < pivot);

		do {
			j--;
		}
		while (array[j] > pivot);

		if (i >= j)
			return j;
		swap_three(array, i, j);
		print_array(array, size);
	}
}

/**
 * swap_three - Swaps two integers
 * @a: Pointer to the first integer
 * @b; Pointer to the second integer
 */
void swap_three(int *array, int a, int b)
{
	int temp = array[a];
	array[a] = array[b];
	array[b] = temp;
}
