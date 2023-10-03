#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

listint_t *add_node(listint_t **head, listint_t *new_node);
size_t knuth_log(size_t x);
/* double log(double x); */
/* int pow(int x, int y); */
int _pow_recursion(int x, int y);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
listint_t *swap(listint_t **head, listint_t *left, listint_t *right);
int swap_ints(int *x, int *y);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
size_t partition(int *array, int lo, int hi, size_t size);
void selection_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void sort(int *array, int lo, int hi, size_t size);
void quick_sort(int *array, size_t size);

#endif
