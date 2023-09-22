#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion Sort algorithm
 *
 * @list: A pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current)
	{
		listint_t *insertion_point = current;

		while (insertion_point->prev && insertion_point->n <
				insertion_point->prev->n)
		{
			listint_t *prev_node = insertion_point->prev;
			listint_t *next_node = insertion_point->next;

			prev_node->next = next_node;
			if (next_node)
			{
				next_node->prev = prev_node;
			}
			insertion_point->prev = prev_node->prev;
			prev_node->prev = insertion_point;
			insertion_point->next = prev_node;

			if (insertion_point->prev)
				insertion_point->prev->next = insertion_point;
			else
				*list = insertion_point;
			print_list(*list);
		}
		current = current->next;
	}
}
