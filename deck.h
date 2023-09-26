#ifndef DECK_H
#define DECK_H
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
/**
 * enum kind_e - represents the four kinds of playing cards
 * @SPADE: type 1
 * @HEART: type 2
 * @CLUB: type 3
 * @DIAMOND: type 4
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;
/**
 * struct card_s - Playing card
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;
/**
 * struct deck_node_s - Deck of card
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;
void sort_deck(deck_node_t **deck);
#endif
