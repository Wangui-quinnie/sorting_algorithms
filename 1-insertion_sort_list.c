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
	listint_t *next_node, *prev_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		next_node = current->next;
		prev_node = current->prev;

		while (prev_node != NULL && prev_node->n > current->n)
		{
			prev_node->next = current->next;
			if (current->next != NULL)
				current->next->prev = prev_node;
			current->prev = prev_node->prev;
			current->next = prev_node;

			if (prev_node->prev != NULL)
				prev_node->prev->next = current;
			else
				*list = current;
			prev_node->prev = current;
			print_list(*list);
			prev_node = current->prev;
		}
		current = next_node;
	}
}
