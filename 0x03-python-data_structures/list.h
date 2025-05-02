#include "lists.h"

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the head pointer
 * Return: New head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
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
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to head of list
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow, *fast, *rev, *temp;

    if (head == NULL || *head == NULL)
        return (1);

    slow = fast = *head;

    /* Find midpoint using slow and fast pointers */
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Reverse second half */
    rev = reverse_list(slow);
    temp = rev;

    /* Compare first and second halves */
    while (temp)
    {
        if ((*head)->n != temp->n)
        {
            reverse_list(rev);  /* Optional: restore original list */
            return (0);
        }
        *head = (*head)->next;
        temp = temp->next;
    }

    reverse_list(rev);  /* Optional: restore list */
    return (1);
}
