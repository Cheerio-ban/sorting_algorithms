#include "sort.h"
#include <stdio.h>

/**
 * swap_node - swaps two nodes
 * @curr: one of the nodes to be swap
 * @next: one of the nodes to be swap
 * Return: Nothing
 */

void swap_node(listint_t *curr, listint_t *next)
{
	listint_t *pcurr, *nnext;

	pcurr  = curr->prev;
	nnext = next->next;

	curr->next = nnext;
	if (pcurr)
		curr->prev->next = next;
	curr->prev = next;

	if (nnext)
		next->next->prev = curr;

	next->next = curr;
	next->prev = pcurr;

}


/**
 * compare - compare the value of two nodes
 * @list: head of the doubly linkedlist
 * @curr: one of the nodes to be swap
 * @next: one of the nodes to be swap
 * @swap: flag to know if nodes were swap
 * Return: 1 if @curr node value is greater @next node value or 0 if not
 */

int compare(listint_t **list, listint_t *curr, listint_t *next, int *swap)
{
	if (curr && curr->n > next->n)
	{
		*swap = 1;
		swap_node(curr, next);
		if (curr == *list)
			*list = curr->prev;
		print_list(*list);
		return (1);
	}

	return (0);
}

/*
 * cocktail_sort_list - sorts a doubly linkedlist using the cocktail
 * shaker sort algorithm
 * @list: head of list to be sorted
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *j, *k = NULL, *curr, *next;
	int swap = 1;

	if (!list || !(*list))
		return;
	while (swap)
	{
		swap = 0;
		j = *list;
		while (j && j->next)
		{
			curr = j, next = j->next;
			if (!compare(list, curr, next, &swap))
				j = j->next;
		}
		if (!swap)
			break;
		swap = 0;
		k = j;
		while (k && k->prev && k->prev->prev)
		{
			curr = k->prev->prev, next = k->prev;
			if (!compare(list, curr, next, &swap))
				k = k->prev;
		}
	}
}
