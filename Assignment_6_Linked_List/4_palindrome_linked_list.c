/* Program to check if given singly-linked list is palindrome or not.
 *
 * Q-234 LeetCode
 *
 * @Ujjwal, 1910991390, 24/08/2021
 * Assignment 6 (Linked list)
 */

/**
 * Definition of singly-Linked list.
 * struct ListNode {
 *     int val;
 *     int *next;
 * };
 */

bool isPalindrome(struct ListNode* head) {

    struct ListNode *hare = head;
    struct ListNode *tortoise = head;

    //finding middle element using hare and tortoise method

    while(hare != NULL && hare->next != NULL)
    {
	hare = hare -> next -> next;
	tortoise = tortoise -> next;
    }

    struct ListNode *before = NULL;
    struct ListNode *current = tortoise;
    struct ListNode *after = NULL;

    //reversing the list from middle element to end of list

    while(current != NULL)
    {
	after = current -> next;
	current->next = before;
	before = current;
	current = after;
    }
    
    hare = head;
    
    //comparing first half of list to the second reversed part

    while(before != NULL)
    {
	if(hare -> val != before -> val)
	{
	    return false;
	}

	hare = hare -> next;
	before = before -> next;
    }

    return true;
}
