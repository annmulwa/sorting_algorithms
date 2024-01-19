#include "sort.h"

/**
 * swapping - function performs swapping of two ints
 * @m: first int to be swapped
 * @n: second int to be swapped
 */
void swapping(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}

/**
 * selection_sort - sorts a list using selection sort
 * @array: array to be sorted
 * @size: size of array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	int *min_int;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_int = array + i;
		for (j = i + 1; j < size; j++)
			min_int = (array[j] < *min_int) ? (array + j) : min_int;
		if ((array + i) != min_int)
		{
			swapping(array + i, min_int);
			print_array(array, size);
		}
	}
}
