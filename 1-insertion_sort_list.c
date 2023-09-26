#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * Description: insertion sort algorithm implementation
 * for doubly linked list structure
 *
 * @list: pointer to head node of list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current_node, *tail, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current_node = (*list)->next;
	tail = *list;

	while (current_node)
	{
		if (tail->n > current_node->n)
		{
			temp = current_node;
			current_node = current_node->next;
			while (temp->prev && temp->prev->n > temp->n)
			{
				temp = swap(list, temp->prev, temp);
				print_list(*list);
			}
		}
		else
		{
			tail = current_node;
			current_node = current_node->next;
		}
	}
}

/**
 * swap - swaps two adjacent nodes
 * Description: swaps two adjacent nodes in a
 * doubly-linked list
 *
 * @head: pointer to list structure incase changing first node
 * @left: pointer to left-most node
 * @right: pointer to right-most node
 *
 * Return: listint_t node, right-most node from the swap
 */
listint_t *swap(listint_t **head, listint_t *left, listint_t *right)
{
	listint_t *__attribute((unused))tmp = *head;

	if (left == NULL || right == NULL || left->next
	    != right || right->prev != left)
		return (NULL);

	right->prev = left->prev;
	left->next = right->next;
	right->next = left;
	left->prev = right;

	if (right->prev)
		right->prev->next = right;

	if (left->next)
		left->next->prev = left;
	if (*head == left)
		*head = right;
	return (right);
}
