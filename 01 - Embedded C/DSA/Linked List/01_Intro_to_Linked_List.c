// Non Conituguous memory allocation, i.e, ramdon memory allocation to data (Data, Pointer to next node)
// Used as replacement of Array. Since, Size of Array is pre-defined, i.e., can't be extended, hence can store fix number of element 
// Uses the memory precisely, as List can be extended as required
// Node : Data | Pointer ((Struct Node *)points to next node OR holds address of next node) [in heap]
// for last node, poiner is set to NULL. Declaring the end of Linked List
// memory consumption INCREASES Linearly with number of elements
// can be implemented using Structure

struct node
{
    int data;
    struct node *Next; // Self-Referencing Structure : ye point karega eske jaise ek element ko
};
