#include "deck.h"

/**
 * compare_cards - custom comparison function used by the qsort function
 * to compare two card nodes for sorting.
 * @a: A pointer to the first card node.
 * @b: A pointer to the second card node.
 * Return: - value if a should come before b
 * 0 if a and b are equal
 * + if a should come after b
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;

	if (node_a->card->kind != node_b->card->kind)
	{
		return (node_a->card->kind - node_b->card->kind);
	}
	return (strcmp(node_a->card->value, node_b->card->value));
}
/**
 * sort_deck - Sorts a deck of cards
 * @deck: A pointer to a pointer to the head of the linked list
 * representing the deck of cards
 * Return: Updated through the deck pointer parameter
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *current = *deck;
	deck_node_t *sorted_deck[52];
	int i = 0;

	while (current != NULL)
	{
		sorted_deck[i++] = current;
		current = current->next;
	}
	qsort(sorted_deck, 52, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < 52 - 1; i++)
	{
		sorted_deck[i]->next = sorted_deck[i + 1];
		sorted_deck[i + 1]->prev = sorted_deck[i];
	}
	sorted_deck[0]->prev = NULL;
	sorted_deck[51]->next = NULL;
	*deck = sorted_deck[0];
}
