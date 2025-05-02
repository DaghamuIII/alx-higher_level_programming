#include "lists.h"

listint_t *reverse_list(listint_t *head);

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to the head of the list.
 * Return: 1 if palindrome, 0 if not.
 */
int is_palindrome(listint_t **head)
{
    listint_t *slow = *head, *fast = *head;
    listint_t *second_half, *prev = NULL;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    // Find the middle using slow and fast pointers
    while (fast && fast->next)
    {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // If list has odd number of elements, skip middle
    if (fast)
        slow = slow->next;

    // Reverse the second half
    second_half = reverse_list(slow);

    // Compare both halves
    listint_t *first_half = *head;
    listint_t *check = second_half;
    int palindrome = 1;

    while (check)
    {
        if (first_half->n != check->n)
        {
            palindrome = 0;
            break;
        }
        first_half = first_half->next;
        check = check->next;
    }

    // Restore second half (optional but cleaner)
    reverse_list(second_half);

    return palindrome;
}

/**
 * reverse_list - Reverses a singly linked list.
 * @head: Pointer to the head node.
 * Return: New head of the reversed list.
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

    return prev;
}
