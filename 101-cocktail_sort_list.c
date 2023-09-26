#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = *list, *right = NULL, *current;
	int swapped;

	if (!list || !(*list) || !((*list)->next))
		return;
	do
	{
		swapped = 0;
		for (current = left; current->next != right; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, &current, &current->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		right = current;
		for (current = right; current->prev != left; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, &current, &current->prev);
				print_list(*list);
				swapped = 1;
			}
		}
		left = current;
	}
	while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *temp_a = *a, *temp_b = *b;

	if (temp_a->prev)
		temp_a->prev->next = temp_b;
	else
		*list = temp_b;
	if (temp_b->next)
		temp_b->next->prev = temp_a;
	temp_a->next = temp_b->next;
	temp_b->prev = temp_a->prev;
	temp_a->prev = temp_b;
	temp_b->next = temp_a;
}
