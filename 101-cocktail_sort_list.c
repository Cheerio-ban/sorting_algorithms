#include "sort.h"

/*
 * cocktail_sort_list - sorts a doubly linkedlist using the cocktail shaker sort algorithm
 * @list: head of list to be sorted
 * Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *h;
	int swap = 1;

	if (!list || !(*list))
		return;

	h = *list;

	while(swap)
	{
		listint_t *j = h, *k = NULL;

		swap = 0;
		while(j && j->next)
		{
			listint_t *curr, *next, *prev;
			
			curr = j;
			next = j->next;
			prev = j->prev;

			if (prev && prev->n > curr->n)
			{
				swap = 1;
				curr->next = prev;
				curr->prev = prev->prev;

				if (prev->prev)
					prev->prev->next = curr;
				prev->next = next;
				prev->prev = curr;

				if (next)
					next->prev = prev;

				if (prev == *list)
					*list = prev->prev;
				print_list(*list);
				j = prev->next;
			}

			else
				j = j->next;
		}

		if (!swap)
			break;

		swap = 0;
		k = j;
		while (k && k->prev && k->prev && k->prev && k != *list)
		{
			listint_t *curr, *prev, *next;
			curr = k;
			prev = k->prev;
			next = k->next;

			if (prev && prev->n > curr->n)
			{
				swap = 1;

				curr->prev = prev->prev;
				curr->next = prev;

				if (prev->prev)
					prev->prev->next = curr;

				prev->next = next;
				prev->prev = curr;

				if (next)
					next->prev = prev;

				if (prev == *list)
					*list = prev->prev;
				print_list(*list);
			}

			k = k->prev;
		}
	}
}
