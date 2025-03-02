// LINKED LIST CREATION

// Linked List = Head Node (First Node), Second Node, Third Node...Final Node(last data, NULL)

// head = (struct node *)malloc(sizeof(struct node));   //head is a "struct pointer", hence arrow operator is used access it's element. 

// second_node = (struct node *)malloc(sizeof(struct node));

// head->data = 7 
// for linking head to second node, head->next = second node

// LINKED LIST TRAVERSAL
// pointer points to node and keeps on pointing next node till NULL is reached

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedlistTraversal(struct node *ptr);

int main()
{
    // Allocating memory for nodes in Linked list in HEAP
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));
    
    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));

    //Linking the nodes
    head->data = 7;
    head->next = second; //linking head to second node

    second->data = 11;
    second->next = third; //linking head to third node

    third->data = 66;
    third->next = NULL; // terminating the linked list

    //Traversing the Linked List
    linkedlistTraversal(head);

    return 0;
}


void linkedlistTraversal(struct node *ptr) // For Travcersing the Linked List. Pointing towards head and will be moved to next node till NULL
{
    while(ptr!=NULL)
    {
        printf("Element is : %d\n",ptr->data);
        //ptr++; // no, we want the pointer to point to the next node
        ptr = ptr->next;
    }
}
