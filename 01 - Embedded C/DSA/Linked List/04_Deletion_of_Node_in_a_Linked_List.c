// Case I   :   Deletion of First Node
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linklistTraversal(struct node *ptr);

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

    printf("\nList before Deletion : \n");
    linklistTraversal(head);

    struct node *ptr = head;
    head = head->next;
    free(ptr);

    printf("\nList after Deletion : \n");
    linklistTraversal(head);

    return 0;
}

// void linklistTraversal(struct node *ptr)
// {
//     while(ptr!=NULL)
//     {
//         printf("Element is : %d\n",ptr->data);
//         ptr = ptr->next;
//     }
// }

// Case II   :   Deletion of Node in Between

// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void linklistTraversal(struct node *ptr);
// struct node *deletionInBetween(struct node *head, int element);

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

//     printf("\nList before Deletion : \n");
//     linklistTraversal(head);

//     head = deletionInBetween(head, 2);
//     printf("\nList After Deletion : \n");
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

// struct node *deletionInBetween(struct node *head, int element)
// {
//     struct node *p;
//     p = (struct node *)malloc(sizeof(struct node));

//     struct node *q;
//     q = (struct node *)malloc(sizeof(struct node));

//     int i=0;
//     while(i!=(element-1))
//     {
//         p = p->next;
//         i++;
//     }

//     q = p->next;
//     p->next = q->next;
//     free(q);
//     return head;
// }
// Case III   :   Deletion of Last Node 

// #include<stdio.h>
// #include<stdlib.h>

// struct node
// {
//     int data;
//     struct node *next;
// };

// void *linklistTraversal(struct node *ptr);

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

   

//     printf("\nList before Deletion : \n");
//     struct node *p;
//     p = (struct node *)malloc(sizeof(struct node));
//     p = linklistTraversal(head);



//     return 0;
// }

// void *linklistTraversal(struct node *ptr)
// {
//     struct node *p;
//     p = (struct node *)malloc(sizeof(struct node));
//     p = ptr--;

//     while(ptr!=NULL)
//     {
//         printf("Element is : %d\n",ptr->data);
//         ptr = ptr->next;
//     }

//     return p;
// }
// Case IV   :   Deletion Node with given Value/Key