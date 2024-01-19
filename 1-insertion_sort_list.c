#include "sort.h"

/**
 * swapping_node - swaps node of a doubly linked list
 * @h: pointer to head of the list
 * @node1: pointer to first node to be swapped
 * @node2: second node to be swapped
 */
void swapping_node(listint_t **h, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*h = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
/**
 * insertion_sort_list - sorts list by insertion method
 * @list: pointer to the list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *temp, *ins;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
		return;
	for (itr = (*list)->next; itr != NULL; itr = temp)
	{
		temp = itr->next;
		ins = itr->prev;
		while (ins != NULL && itr->n < ins->n)
		{
			swapping_node(list, &ins, itr);
			print_list((const listint_t *)*list);
		}
	}
}
