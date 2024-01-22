#include "sort.h"

/**
 * qwap_nodes - Func swaping 2 nodes in a listint_t.
 * @h: Pointing to the head of the created doubly-linked list.
 * @n1: Pointing to the 1st node to swap.
 * @n2: The second node to swap.
 */
void qwap_nodes(listint_t **k, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*k = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list -Func sorting a doubly linked list of ints
 * with the use of the insertion sort algorithm.
 * @list: Pointing to the head of a doubly-linked list of integers.
 * Description: Printing the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = temp)
	{
		temp = itr->next;
		insert = itr->prev;
		while (insert != NULL && itr->n < insert->n)
		{
			qwap_nodes(list, &insert, itr);
			print_list((const listint_t *)*list);
		}
	}
}
