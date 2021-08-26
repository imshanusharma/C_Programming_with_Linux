/* Program to remove nth node from the end of a linked list.
 *
 * LeetCode Q-19
 *
 * @Ujjwal, 1910991390, 26/08/2021
 * Assignment 6 (Linked List)
 */

/**
 * Definition of singly linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* Function to delete Nth node from the end.
 *
 * Parameter :
 * head: Pointer pointing to the head of the linked list
 * n : value of nth node from the end
 *
 * Return
 * List after removing Nth node from the end.
 */

struct ListNode* removeNthFromEnd(struct ListNode *head, int n) {

    //edge cases

    if(head -> next == NULL && n == 1)
    {
	return NULL;
    }
    if(head -> next -> next == NULL)
    {
	if(n == 1)
	{
  	    head -> next = NULL;
	    return head;
	}
	else
	{
	    head = head -> next;
	    return head;
	}
    }

    int len = 0;
    struct ListNode *temp = head;

    //calculating length of the linked list

    while(temp != NULL)
    {
	temp = temp -> next;
	len++;
    }

    //edge case

    if(len == n)
    {
	head = head -> next;
	return head;
    }

    //deleting nth node from the end

    temp = head;
    int k = len - n - 1;

    while(k--)
    {
	temp = temp -> next;
    }

    temp -> next = temp -> next -> next;

    return head;
}
