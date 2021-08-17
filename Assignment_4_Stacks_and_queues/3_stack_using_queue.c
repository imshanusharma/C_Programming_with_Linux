/*To implement stack operations (Push, pop, peek, empty) using queues
 * 
 * LeetCode Q)155
 *
 * @UJJWAL, 1910991390, 17/08/2021
 * Assignment 4 (Stack and Queues)
 *
 */

typedef struct {
    
    int data;

} MyStack;

/** Initialize your data structure here. */

    int size1, size2;
    int head1, head2;
    int tail1, tail2;


MyStack* myStackCreate() 
{    
     MyStack *queue1 = (MyStack *)calloc(100,sizeof(MyStack));
     size1 = 0;
     head1 = 0;
     tail1 = 0;
     return queue1;
}

MyStack* myStackCreate2() 
{    
     MyStack *queue2 = (MyStack *)calloc(100,sizeof(MyStack));
     size2 = 0;
     head2 = 0;
     tail2 = 0;
     return queue2;
}

/** Push element x onto stack. */

void myStackPush(MyStack* queue1, int x) 
{
    MyStack *queue2 = myStackCreate2();
    
    int temp = 0;
    int size = size1;
    
    for(int i = head1; i <= tail1 - 1; i++)
    {
        queue2[temp++].data = queue1[i].data;
    }
    
    myStackCreate();
    
    queue1[tail1++].data = x;
    for(int i = 0; i < size; i++)
    {
        queue1[tail1++].data = queue2[i].data;
    }

    size1 = size + 1;
}

/** Removes the element on top of the stack and returns that element. */

int myStackPop(MyStack* queue1) 
{
    int element = queue1[head1].data;
    head1++;
    size1--;
    return element;
}

/** Get the top element. */
int myStackTop(MyStack* queue1)
{
    return queue1[head1].data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* queue1) 
{
    if(size1 == 0)
    {
	return true;
    } 
    return false;
}

void myStackFree(MyStack* queue1) 
{
    free(queue1);    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
