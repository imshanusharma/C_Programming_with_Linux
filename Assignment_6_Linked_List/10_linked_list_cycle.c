/* Program to find the node from where the cycle begins (if exists) in a singly-linked list.
 *
 * LeetCode Q-142
 *
 * @UJJWAL, 1910991390, 25/08/2021
 * Assignment 6 (Linked List)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {

    struct ListNode *hare = head;
    struct ListNode *tortoise = head;

    //finding if cycle exists using hare and tortoise method

    while(hare != NULL && hare->next != NULL)
    {
	hare = hare -> next -> next;
	tortoise = tortoise -> next;
	
	//if cycle found, reset tortoise to head and start moving hare and tortoise by single steps

	if(hare == tortoise)
	{
	    tortoise = head;

	    while(tortoise != hare)
	    {
		tortoise = tortoise -> next;
		hare = hare -> next;
	    }
	    return tortoise;
	}
    }
    return NULL;
}
