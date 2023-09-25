#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail Shaker Sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *right, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		current = *list;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next);
				if (current->prev == NULL)
					*list = current;
				swapped = 1;
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		right = current;

		while (right->prev != NULL)
		{
			if (right->n < right->prev->n)
			{
				swap_nodes(right->prev, right);
				if (right->next == NULL)
					current = right;
				swapped = 1;
				print_list(*list);
			}
			else
				right = right->prev;
		}
	}
	while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: Pointer to the first node to be swapped
 * @node2: Pointer to the second node to be swapped
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
	if (node1 == NULL || node2 == NULL)
		return;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
