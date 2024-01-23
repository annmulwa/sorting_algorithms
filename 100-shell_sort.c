#include "sort.h"

/**
 * swapping - swaps two integers in an array
 * @m: first integer to be swapped
 * @n: second integer to be swapped
 */
void swapping(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}

/**
 * shell_sort - sorts an array of integers in ascending
 *              order using the shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t interval, i, j;

	if (array == NULL || size < 2)
		return;

	for (interval = 1; interval < (size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swapping(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, size);
	}
}
