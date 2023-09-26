#include <stdio.h>
#include "sort.h"

/**
  *insertion_sort_list- sorts a doubly linked listin ascending order
  *using the insertion sort algorithm.
  *@list: pointer to the pointer of the doubly linked list.
  */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;
	listint_t *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		prev_node = current->prev;

		while (prev_node != NULL && prev_node->n > current->n)
		{
			if (current->next != NULL)
			{
				current->next->prev = prev_node;
			}
			prev_node->next = current->next;
			current->prev = prev_node->prev;
			current->next = prev_node;
			prev_node->prev = current;

			if (current->prev == NULL)
			{
				*list = current;
			}
			else
			{
				current->prev->next = current;
			}
			print_list(*list);
			prev_node = current->prev;
		}
		current = current->next;
	}
}
