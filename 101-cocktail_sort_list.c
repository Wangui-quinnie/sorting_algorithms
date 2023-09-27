#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 *
 * @list: A pointer to the head of the list.
 * @a: The first node to swap.
 * @b: The second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev != NULL)
		a->prev->next = b;
	else
		*list = b;
	if (b->next != NULL)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail Shaker Sort algorithm.
 *
 * @list: A pointer to a pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int s = 1;
	listint_t *end, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (s)
	{
		s = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				s = 1;
			}
			else
				current = current->next;
		}
		if (!s)
			break;
		s = 0;
		end = current;

		while (end->prev != NULL)
		{
			if (end->n < end->prev->n)
			{
				swap_nodes(list, end->prev, end);
				print_list(*list);
				s = 1;
			}
			else
				end = end->prev;
		}
	}
}
