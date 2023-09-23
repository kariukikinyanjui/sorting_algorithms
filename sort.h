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
int _putchar(char c);
void custom_putint(int num);
int lomuto_partition(int *array, size_t size, int low, int high);
void quicksort(int *array, size_t size, int start, int end);
void swap(int *a, int *b);
typedef enum kind_e
{
    SPADE = 0,
    HEART,
    CLUB,
    DIAMOND
} kind_t;
#endif
