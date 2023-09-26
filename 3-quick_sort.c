#include <stdio.h>
#include "sort.h"

/**
  *quick_sort - sorts an array of integers in ascending order using the quick
  *sort algorithm and lomuto partition scheme.
  *@array: the array to be sorted.
  *@size: the number of elements in the array.
  */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursively sorts an array using Quick Sort.
 * @array: The array to be sorted.
 * @left: The lower bound of the partition.
 * @right: The upper bound of the partition.
 * @size: The total number of elements in the array.
 */
void recursive_quick_sort(int *array, int left, int right, size_t size)
{
	if (left < right)
	{
		int pivot_index = lomuto_partition(array, left, right, size);

		recursive_quick_sort(array, left, pivot_index - 1, size);
		recursive_quick_sort(array, pivot_index + 1, right, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort.
 * @array: The array to be partitioned.
 * @left: The lower bound of the partition.
 * @right: The upper bound of the partition.
 * @size: The total number of elements in the array.
 *
 * Return: The pivot index.
 */
int lomuto_partition(int *array, int left, int right, size_t size)
{
	int pivot = array[right];
	int i = left - 1, j, temp;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (i != j)
				print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[right];
	array[right] = temp;
	if (i + 1 != right)
		print_array(array, size);
	return (i + 1);
}
