/* Program to reverse a linked list between two given nodes
 *
 * LeetCode - Q92
 *
 * @UJJWAL, 1910991390, 30/08/2021
 * Assignment 2 (Linked List)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {

    if(head -> next  == NULL)
    {
	return head;
    }

    struct ListNode *l1 = head;

    struct ListNode *l2 = head;
    struct ListNode *l3 = head;
    struct ListNode *n1 = NULL;
    struct ListNode *n2 = NULL;

    if(left >= right)
    {
	return head;
    }
    for(int i = 0; i < left - 1; i++)
    {
	n1 = l1;
	l1 = l1 -> next;
	l2 = l2 -> next;
    }
    for(int i = 0; i < right - 1; i++) 
    {
	l3 = l3 -> next;
	n2 = l3 -> next;
    }

    struct ListNode *temp1 = NULL;
    struct ListNode *temp2 = NULL;

    while(l1 != n2)
    {
	temp2 = temp1;
	temp1 = l1;
	l1 = l1 -> next;
	temp1 -> next = temp2;
    }

    if(left > 1)
    {
	n1 -> next = temp1;
	l2 -> next = n2;
	return head;
    }
    else
    {
	l2 -> next = n2;
	return temp1;
    }
}
