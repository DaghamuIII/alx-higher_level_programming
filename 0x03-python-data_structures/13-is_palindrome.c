#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 *
 * Return: 1 if it's a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    int *values;
    int i, len;
    listint_t *current;

    if (head == NULL || *head == NULL)
        return (1);

    len = listint_len(*head);
    values = malloc(sizeof(int) * len);
    if (values == NULL)
        return (0);

    current = *head;
    for (i = 0; i < len; i++)
    {
        values[i] = current->n;
        current = current->next;
    }

    for (i = 0; i < len / 2; i++)
    {
        if (values[i] != values[len - 1 - i])
        {
            free(values);
            return (0);
        }
    }

    free(values);
    return (1);
}

/**
 * listint_len - counts the number of elements in a linked list
 * @h: head of the list
 *
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
    int length = 0;

    while (h != NULL)
    {
        length++;
        h = h->next;
    }

    return (length);
}
