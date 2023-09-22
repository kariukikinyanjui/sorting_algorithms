#include "sort.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * custom_putint - custom integer to string conversion function
 * @num: function parameter
 */
void custom_putint(int num)
{
	char buffer[20];
	int index = 0;

	if (num < 0)
	{
		_putchar('-');
		num = -num;
	}
	do
	{
		buffer[index++] = (char)(num % 10 + '0');
		num /= 10;
	}
	while (num > 0);

	while (index > 0)
	{
		_putchar(buffer[--index]);
	}
}

/**
 * selection_sort - Sorts an array of integers in ascending order using the
 * Selection Sort algorithm
 * @array: The Array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, k, min_idx;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;

			for (k = 0; k < size; k++)
			{
				if (k > 0)
					_putchar(',');
				custom_putint(array[k]);
			}
			_putchar('\n');
		}
	}
}
