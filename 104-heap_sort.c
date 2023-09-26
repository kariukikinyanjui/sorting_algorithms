#include "sort.h"

/**
 * swap_two - Swaps two elements in an array.
 * @array: The array containing the elements to be swapped.
 * @size: The size of the array.
 * @a: Index of the first element to be swapped.
 * @b: Index of the second element to be swapped.
 */
void swap_two(int *array, size_t size, int a, int b)
{
	int temp;

	if (a != b)
	{
		temp = array[a];
		array[a] = array[b];
		array[b] = temp;
		print_array(array, size);
	}
}

/**
 * sift_down - Pereforms the sift_down operation in the heap sort algorithm.
 * @array: The array to be sorted as a max heap.
 * @size: The Size of the array.
 * @start: The index of the element to sift down.
 * @end: The end index of the heap.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;
	size_t child, swap_idx;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;
		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;
		if (swap_idx != root)
		{
			swap_two(array, size, root, swap_idx);
			root = swap_idx;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array of integers in asacending order using the Heap
 * sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size <= 1)
		return;
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, i, size - 1);
	for (i = size - 1; i > 0; i--)
	{
		swap_two(array, size, 0, i);
		sift_down(array, size, 0, i - 1);
	}
}
