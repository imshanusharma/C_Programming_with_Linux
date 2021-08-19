/* Program to rotate a linked list by K times.
 * 
 * Q61 - LeetCode
 *
 * @Ujjwal, 1910991390, 19/08/2021
 * Assignment 6 (Linked List)
 */

/**
 * Definition for singly Linked list
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* rotateRight(struct ListNode* head, int k) {

    /* Edge Cases */

    if(head == NULL || head -> next = NULL || K == 0)
    {
	return head;
    }

    struct ListNode* current = head;

    int len = 1;

    /* Traversing to end and calculating length of list */

    while(current->next && ++len)
    {
	current = current -> next;
    }

    current -> next = head;

    /* if k > length, find modulas of k % len to get the min rotation required to avoid repetition */

    k = k % len;

    k = len - k;

    while(k--)
    {
	current = current -> next;
    }

    head = current -> next;
    current -> next = NULL;

    return head;
}
