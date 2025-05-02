#include "lists.h"

/**
 * reverse_list - Reverses a singly linked list.
 * @head: Pointer to the head node of the list to reverse.
 *
 * Return: New head of the reversed list.
 */
static listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;

    while (head)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the linked list.
 *
 * Return: 1 if the list is a palindrome, 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *second_half, *first_half;
    int result = 1;

    if (head == NULL || *head == NULL || (*head)->next == NULL)
        return (1);

    slow = fast = *head;
    /* Find midpoint (slow will point to middle) */
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half */
    second_half = reverse_list(slow->next);
    first_half = *head;

    /* Compare both halves */
    while (second_half)
    {
        if (first_half->n != second_half->n)
        {
            result = 0;
            break;
        }
        first_half = first_half->next;
        second_half = second_half->next;
    }

    /* Restore original list structure */
    slow->next = reverse_list(reverse_list(slow->next));

    return (result);
}
