#include <stdio.h>
#include "sort.h"

/**
  *selection_sort - sorts an array of integers in ascending order using
  *the selection sort algorithm.
  *@array: the array to be sorted.
  *@size: the number of elements in the array.
  */
void selection_sort(int *array, size_t size)
{
	size_t i, j, small;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		small = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[small])
				small = j;
		}
		temp = array[small];
		array[small] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
