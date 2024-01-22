#include "sort.h"

void qwap_node_ahead(listint_t **list, listint_t **taillight, listint_t **shaker);
void qwap_node_behind(listint_t **list, listint_t **taillingt, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * qwap_node_ahead - Func to swap a node in a listint_t
 * doubly-linked list list of ints with the node ahead of it.
 * @list: Pointing  to the head of a doubly-linked list of ints.
 * @taillight: Pointing to the tail of the doubly-linked list.
 * @shaker: Pointing to the current swapping node of the cocktail shaker algo.
 */

void qwap_node_ahead(listint_t **list, listint_t **taillight, listint_t **shaker)
{
	listint_t *temp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = temp;
	else
		*list = temp;
	temp->prev = (*shaker)->prev;
	(*shaker)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *shaker;
	else
		*taillight = *shaker;
	(*shaker)->prev = temp;
	temp->next = *shaker;
	*shaker = temp;
}
/**
 * qwap_node_behind - Func to swap a node in a listint_t
 * doubly-linked list of ints with the node behind it.
 * @list: Pointing to the head of a doubly-linked list of ints.
 * @taillight: Pointing to the tail of the doubly-linked list.
 * @shaker: Pointing to the current swapping node of the cocktail shaker algo.
 */

void qwap_node_behind(listint_t **list, listint_t **taillight, listint_t **shaker)
{
	listint_t *temp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = temp;
	else
		*taillight = temp;
	temp->next = (*shaker)->next;
	(*shaker)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = temp;
	temp->prev = *shaker;
	*shaker = temp;
}

/**
 * cocktail_sort_list - Func sorting a listint_t doubly-linked list of ints in
 * ascending order using the cocktail shaker algorithm.
 * @list: Pointing to the head of a listint_t doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *taillight, *shaker;
	bool shaken_not_stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (taillight = *list; taillight->next != NULL;)
		taillight = taillight->next;

	while (shaken_not_stirred == false)
	{
		shaken_not_stirred = true;
		for (shaker = *list; shaker != taillight; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				qwap_node_ahead(list, &taillight, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				qwap_node_behind(list, &taillight, &shaker);
				print_list((const listint_t *)*list);
				shaken_not_stirred = false;
			}
		}
	}
}
