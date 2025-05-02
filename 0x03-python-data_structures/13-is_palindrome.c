#include "lists.h"

/**
 * reverse_list - Reverses a linked list
 * @head: Pointer to the first node of the list
 *
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
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 *
 * Return: 1 if it's a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    listint_t *second_half, *first_half, *reversed;
    int result = 1;

    if (!head || !*head || !(*head)->next)
        return (1);

    // Find the middle of the list
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // If the list has odd number of elements, skip the middle one
    if (fast)
        slow = slow->next;

    // Reverse the second half
    reversed = reverse_list(slow);
    second_half = reversed;
    first_half = *head;

    // Compare the two halves
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

    // Restore the original list (optional but good practice)
    reverse_list(reversed);

    return (result);
}
