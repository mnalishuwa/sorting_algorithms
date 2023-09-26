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
	listint_t *current_node = *list, *backtrack, *tail, *temp;

	tail = current_node;
	temp = current_node;

	if (current_node == NULL || current_node->next == NULL)
		return;

	while (current_node)
	{
		if (tail->n > current_node->n)
		{
			temp = current_node;
			tail->next = temp->next;
			current_node = current_node->next;
			backtrack = tail->prev;
			while (backtrack && backtrack->n > temp->n)
			{
				backtrack = backtrack->prev;
			}
			if (backtrack == NULL)
			{
				add_node(list, temp);
				print_list(*list);
				continue;
			}
			temp->next = backtrack->next;
			temp->prev = backtrack;
			if (backtrack->next)
				backtrack->next->prev = temp;
			backtrack->next = temp;
			print_list(*list);
		}
		else
		{
			tail = current_node;
			current_node = current_node->next;
		}
	}
}

/**
 * add_node - add node at the beginning of list
 * Description: add node to start of doubly-linked list
 *
 * @head: pointer to first node in the list
 * @new_node: node
 *
 * Return: listint *, pointer to new node
 */
listint_t *add_node(listint_t **head, listint_t *new_node)
{
	if (new_node == NULL || head == NULL)
		return (NULL);

	new_node->prev = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = NULL;
		return (new_node);
	}

	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}
