#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
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
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
int lomuto_partition(int *array, size_t size, int low, int high);
void quicksort(int *array, size_t size, int high, int low);
void swap(int *a, int *b);
void swap_nodes(listint_t **list, listint_t **a, listint_t **b);
void merge(int *array, int *left, int *right, size_t size);
void swap_two(int *array, size_t size, int a, int b);
void sift_down(int *array, size_t size, size_t start, size_t end);
int get_max(int *array, size_t size);
void counting_sort_radix(int *array, size_t size, int exp);
void bitonic_merge(int *array, size_t size, int dir);
void bitonic_compare(int *array, size_t size, int dir);
void _quick_sort_hoare(int *array, int low, int high, size_t size);
int hoare_partition(int *array, int low, int high, size_t size);
void swap_three(int *array, int a, int b);
#endif
