#include "sort.h"

/**
 * bitonic_compare - Compare and wap two elements if needed.
 * @array: The array of integers.
 * @size: The size of the array.
 * @dir: 1 for ascending, 0 for descending.
 */
void bitonic_compare(int *array, size_t size, int dir)
{
	size_t i, gap = size / 2;
	int temp;

	for (i = 0; i < gap; i++)
	{
		if ((array[i] > array[i + gap]) == dir)
		{
			temp = array[i];
			array[i] = array[i + gap];
			array[i + gap] = temp;
		}
	}
}

/**
 * bitonic_merge - Recursively merge two subarrays of the same direction.
 * @array: The array of integers.
 * @size: The size of the array.
 * @dir: 1 for ascending, o for descending.
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t half = size / 2;

		printf("Merging [%lu/%lu] (%s);\n", size, size, (dir == 1) ?
				"UP" : "DOWN");
		print_array(array, size);

		bitonic_compare(array, size, dir);
		bitonic_merge(array, half, dir);
		bitonic_merge(array + half, half, dir);
	}
}

/**
 * bitonic_sort - Sort an array of integers using the Bitonic sort algorithm.
 * @array: The array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	int up = 1, down = 0;

	if (array == NULL || size < 2)
		return;
	printf("Merging [%lu/%lu] (%s);\n", size, size, "UP");
	print_array(array, size);

	bitonic_sort(array, size / 2);
	bitonic_sort(array + size / 2, size / 2);
	bitonic_merge(array, size, up);

	printf("Result [%lu/%lu] (%s):\n", size, size, "UP");
	print_array(array, size);

	bitonic_merge(array, size, down);

	printf("Result [%lu/%lu] (%s):\n", size, size, "DOWN");
	print_array(array, size);
}
