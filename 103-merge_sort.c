#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge Sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *temp;

	if (array == NULL || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp[i] = array[i];
	}
	recursive_merge_sort(array, temp, 0, size - 1);
	free(temp);
}
/**
 * recursive_merge_sort - Recursively sorts an array using Merge Sort.
 * @array: The array to be sorted.
 * @temp: A temporary array for merging.
 * @left: The leftmost index of the partition.
 * @right: The rightmost index of the partition.
 */
void recursive_merge_sort(int *array, int *temp, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (left < right)
	{
		recursive_merge_sort(array, temp, left, mid);
		recursive_merge_sort(array, temp, mid + 1, right);

		merge(array, temp, left, mid, right);
	}
}
/**
 * merge - Merges two sorted subarrays into a single sorted array.
 * @array: The original array.
 * @temp: A temporary array for merging.
 * @left: The left index of the first subarray.
 * @mid: The right index of the first subarray.
 * @right: The right index of the second subarray.
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, n1);
	printf("[right]: ");
	print_array(array + mid + 1, n2);

	for (i = 0, j = 0, k = left; i < n1 && j < n2; k++)
	{
		if (temp[i] <= temp[j])
		{
			array[k] = temp[i];
			i++;
		}
		else
		{
			array[k] = temp[j];
			j++;
		}
	}
	while (i < n1)
	{
		array[k] = temp[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = temp[j];
		j++;
		k++;
	}
	printf("[Done]: ");
	print_array(array + left, n1 + n2);
}
