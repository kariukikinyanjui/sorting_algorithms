#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *a, *b;
	bool c = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (a = *list; a->next != NULL; a = a->next)
	while (c == false)
	{
		c = true;
		for (b = *list; b != a; b = b->next)
		{
			if (b->n > b->next->n)
			{
				swap_node_forward(list, &a, &b);
				print_list((const listint_t *) * list);
				c = false;
			}
		}
		for (b = b->prev; b != *list; b = b->prev)
		{
			if (b->n < b->prev->n)
			{
				swap_node_behind(list, &a, &b);
				print_list((const listint_t *) * list);
				c = false;
			}
		}
	}
}

/**
 * swap_node_forward - Swaps two nodes in a doubly linked list of integers
 * with the node ahead of it
 * @list: Pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_node_forward(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *temp = (*b)->next;

	if ((*b)->prev != NULL)
		(*b)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*b)->prev;
	(*b)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *b;
	else
		*a = *b;
	(*b)->prev = temp;
	temp->next = *b;
	*b = temp;
}

/**
 * swap_node_behind - Swap a node in a listint_t doubly_linked list of
 * integers with the node behind it.
 * @list: A pointer to the head of a doubly_linked list of integers.
 * @a: A pointer to the tail of the doubly-linked list.
 * @b: A pointer to the current swapping node of the cocktail shaker algo.
 */
void swap_node_behind(listint_t **list, listint_t **a, listint_t **b)
{
	listint_t *temp = (*b)->prev;

	if ((*b)->next != NULL)
		(*b)->next->prev = temp;
	else
		*a = temp;
	temp->next = (*b)->next;
	(*b)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *b;
	else
		*list = *b;
	(*b)->next = temp;
	temp->prev = *b;
	*b = temp;
}
