#include "sort.h"

/**
 * swapping - swaps two integers
 * @m: first int
 * @n: second int
 */
void swapping(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}
/**
 * bubble_sort - uses bubble sort to sort
 * @array: pointer to array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, cnt = size;
	bool sorted = false;

	if (array == NULL || size < 2)
		return;

	while (sorted == false)
	{
		sorted = true;
		for (i = 0; i < cnt - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swapping(array + i, array + i + 1);
				print_array(array, size);
				sorted = false;
			}
		}
		cnt--;
	}
}
