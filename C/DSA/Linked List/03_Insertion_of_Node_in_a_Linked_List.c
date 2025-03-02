// Case I   :   Inserstion at Beginning

// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void linkedlistTraversal(struct node *ptr);
// struct node *insertAtBeginning(int data, struct node *head);


// int main()
// {
//     struct node *head;
//     head = (struct node *)malloc(sizeof(struct node));
    
//     struct node *second;
//     second = (struct node *)malloc(sizeof(struct node));

//     struct node *third;
//     third = (struct node *)malloc(sizeof(struct node));

//     head->data = 7;
//     head->next = second;

//     second->data = 11;
//     second->next = third;

//     third->data = 66;
//     third->next = NULL;

//     printf("List before Traversal : \n");
//     linkedlistTraversal(head);
//     head = insertAtBeginning(56, head);
//     printf("\nList after Traversal : \n");
//     linkedlistTraversal(head);

//     return 0;
// }

// void linkedlistTraversal(struct node *ptr)
// {
//     while(ptr!=NULL)
//     {
//         printf("Element is : %d\n",ptr->data);
//         ptr = ptr->next; 
//     }
// }

// struct node *insertAtBeginning(int data, struct node *head)
// {
//     struct node *newNode = (struct node *)malloc(sizeof(struct node));

//     newNode->data = data;
//     newNode->next = head;
//     return newNode;
// }


// Case II   :   Inserstion in Between

// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void linklistTraversal(struct node *ptr);
// struct node *insertInBetween(int data, struct node *ptr, int index);

// int main()
// {

//     struct node *head;
//     head = (struct node *)malloc(sizeof(struct node));

//     struct node *second;
//     second = (struct node *)malloc(sizeof(struct node));

//     struct node *third;
//     third = (struct node *)malloc(sizeof(struct node));

//     head->data = 7;
//     head->next = second;

//     second->data = 11;
//     second->next = third;

//     third->data = 66;
//     third->next = NULL;

//     printf("List before Inserstion : \n");
//     linklistTraversal(head);
//     head = insertInBetween(56, head, 2);
//     printf("\nList after Insertion : \n");
//     linklistTraversal(head);
    
//     return 0;
// }

// void linklistTraversal(struct node *ptr)
// {
//     while(ptr!=NULL)
//     {
//         printf("Element is  : %d\n",ptr->data);
//         ptr = ptr->next;
//     }
// }

// struct node *insertInBetween(int data, struct node *head, int index)
// {
//     int i = 0;

//     struct node *p = head;
//     while(i!=(index-1))
//     {
//         p = p->next;
//         i++;
//     }

//     struct node *newNode = (struct node *)malloc(sizeof(struct node));

//     newNode->data = data;
//     newNode->next = p->next;
//     p->next = newNode;
//     return head;

// }

// Case III   :   Inserstion at End

// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void linklistTraversal(struct node *ptr);
// struct node *insertAtEnd(int data, struct node *head);

// int main()
// {

//     struct node *head;
//     head = (struct node *)malloc(sizeof(struct node));

//     struct node *second;
//     second = (struct node *)malloc(sizeof(struct node));

//     struct node *third;
//     third = (struct node *)malloc(sizeof(struct node));

//     head->data = 7;
//     head->next = second;

//     second->data = 11;
//     second->next = third;

//     third->data = 66;
//     third->next = NULL;

//     printf("\nList before Insertion\n");
//     linklistTraversal(head);

//     head = insertAtEnd(56, head);
//     printf("\nList after Insertion\n");
//     linklistTraversal(head);

//     return 0;
// }

// void linklistTraversal(struct node *ptr)
// {
//     while(ptr!=NULL)
//     {
//         printf("Element is : %d\n",ptr->data);
//         ptr = ptr->next;
//     }
// }

// struct node *insertAtEnd(int data, struct node *head)
// {
//     struct node *p = (struct node *)malloc(sizeof(struct node));
//     p = head;

//     struct node *newNode = (struct node *)malloc(sizeof(struct node));
//     newNode->data = data;

//     while(p->next!=NULL)
//     {
//         p = p->next;
//     }

//     p->next = newNode;
//     newNode->next = NULL;
//     return head;
// }

// Case IV   :   Inserstion after Node

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linklistTraversal(struct node *ptr);
struct node *insertAfterNode(int data, struct node *prevNode, struct node *head);

int main()
{
    
    struct node *head;
    head = (struct node *)malloc(sizeof(struct node));

    struct node *second;
    second = (struct node *)malloc(sizeof(struct node));

    struct node *third;
    third = (struct node *)malloc(sizeof(struct node));

    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 66;
    third->next = NULL;

    printf("List before Insertion\n");
    linklistTraversal(head);

    head = insertAfterNode(45, second, head);
    printf("\nList after Insertion\n");
    linklistTraversal(head);

    return 0;
}

void linklistTraversal(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element is : %d\n",ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertAfterNode(int data, struct node *prevNode, struct node *head)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}


