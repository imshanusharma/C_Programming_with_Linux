/* Program to merge two sorted Linked list in C
 *
 * LeetCode Q-21
 *
 * @Ujjwal, 1910991390, 28/08/2021
 * Assignment 6 (Linked list)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* Function to merge 2 given Linked List*/

void merge(struct ListNode* l1, struct ListNode* l2){
    
    if(l1 != NULL && l2 != NULL)
    {
    
        if(l1 -> next == NULL)
        {
            l1 -> next = l2;
        }
        else
        {
            merge(l1->next,l2);
        }
    }
}

/* Function to Swap two given Nodes*/

void swap(struct ListNode* a, struct ListNode* b)
{
    int temp;
    temp = a->val;
    a->val = b->val;
    b->val = temp;
}

/* Function to sort given linked list*/

void sort(struct ListNode *l1)
{
    int swapped;
    struct ListNode *ptr1;
    struct ListNode *lptr = NULL;
    
    do
    {
        swapped = 0;
        ptr1 = l1;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->val > ptr1->next->val)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    //edge cases
    
    if(l1 == NULL && l2 == NULL)
    {
        return NULL;
    }
    if(l1 == NULL && l2 -> next == NULL)
    {
        return l2;
    }
    if(l2 == NULL && l1 -> next == NULL)
    {
        return l1;
    }
    
    if(l1 == NULL)
    {
        //merge(l1,l2);
        sort(l2);
        return l2;
    }
    merge(l1,l2);
    sort(l1);
    return l1;
}
