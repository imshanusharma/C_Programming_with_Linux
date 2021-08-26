/* Program to remove duplicate elements from a linked list
 *
 * LeetCode Q-82
 *
 * @Ujjwal, 1910991390, 26/08/2021
 * Assignment 6 (Linked List)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode *head) {

    //edge cases

    if(head == NULL || head -> next == NULL)
    {
	return head;
    }

    //if distinct elements found

    if(head -> val != head -> next -> val)
    {
	head -> next = deleteDuplicates(head->next);
	return head;
    }

    //removing duplicates

    struct ListNode *temp = head;

    while(temp != NULL && temp -> val == head -> val)
    {
	temp = temp -> next;
    }
    
    return deleteDuplicates(temp);
}
