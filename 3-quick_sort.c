#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * quick_sort - sorts an array in ascending
 * @array: a pointer to the beginning of the array
 * @size: size of the array
 *
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}

/**
 * quicksort - recursive function to perform quick sort
 * @array: a pointer to the beginning of the array
 * @low: low index of the partition
 * @high: high index of the partition
 * @size: size of the array
 *
 * Return: nothing
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * partition - Lomuto partition scheme for quick sort
 * @array: a pointer to the beginning of the array
 * @low: low index of the partition
 * @high: high index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int i = low - 1;
	int j;

	pivot = array[high];

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i + 1);
}
