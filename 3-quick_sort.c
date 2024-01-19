#include "sort.h"

void swapping(int *m, int *n);
int dividing(int *array, size_t size, int leftside, int rightside);
void sorting(int *array, size_t size, int leftside, int rightside);
void quick_sort(int *array, size_t size);

/**
 * swapping - swaps two integers.
 * @m: first integer to be swapped.
 * @n: second integer to be swapped.
 */
void swapping(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}

/**
 * dividing - divides an array into two
 * @array: array to be divided
 * @size: size of the arrray
 * @leftside: the left side of the array
 * @rightside: the right side of the array
 * Return: the final index to be partitioned
 */
int dividing(int *array, size_t size, int leftside, int rightside)
{
	int *axis, top, down;

	axis = array + rightside;
	for (top = down = leftside; down < rightside; down++)
	{
		if (array[down] < *axis)
		{
			if (top < down)
			{
				swapping(array + down, array + top);
				print_array(array, size);
			}
			top++;
		}
	}

	if (array[top] > *axis)
	{
		swapping(array + top, axis);
		print_array(array, size);
	}

	return (top);
}

/**
 * sorting - function to implement the quicksort algorithm through recursion
 * @array: array to be sorted
 * @size: size of the array
 * @leftside: left side of the array
 * @rightside: right side of the array
 */
void sorting(int *array, size_t size, int leftside, int rightside)
{
	int divide;

	if (rightside - leftside > 0)
	{
		divide = dividing(array, size, leftside, rightside);
		sorting(array, size, leftside, divide - 1);
		sorting(array, size, divide + 1, rightside);
	}
}

/**
 * quick_sort - sorts an array of integers using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sorting(array, size, 0, size - 1);
}
