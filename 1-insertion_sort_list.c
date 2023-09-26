#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 * @list: A pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *next;

	if (!list || !*list || !(*list)->next)
		return;
	current = *list;
	while (current)
	{
		next = current->next;
		sorted = current->prev;

		while (sorted && sorted->n > current->n)
		{
			sorted->next = current->next;
			if (current->next)
				current->next->prev = sorted;
			current->prev = sorted->prev;
			if (sorted->prev)
				sorted->prev->next = current;
			else
				*list = current;
			current->next = sorted;
			sorted->prev = current;

			print_list(*list);
			sorted = current->prev;
		}
		current = next;
	}
}
