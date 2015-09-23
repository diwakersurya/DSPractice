#include <iostream>
#include <malloc.h>

using namespace std;

struct node {
int data;
struct node *next;
} ;
//function to insert node in the beggining of the list
void insert_node_in_beg(struct node **head,int data)
{

    struct node *temp=(struct node *)malloc(sizeof(struct node)) ;
    temp->data=data;
    temp->next=(*head);
    (*head)=temp;

 }
 //function to insert node in the end of the list
 void insert_node_in_end(struct node *head,int data)
{

    struct node *temp=(node *)malloc(sizeof(struct node)) ;
    temp->data=data;
    temp->next=NULL;
    struct node *iter=head;
    //iter->next represents last node
   while (iter->next != NULL)
   {
     iter=iter->next;
   }
   iter->next=temp;

 }
// function to insert node in the list after a node having a particular value.
  void insert_node_after(struct node *head,int valToFind,int data)
{
    struct node *temp=(node *)malloc(sizeof(struct node)) ;
    temp->data=data;
    temp->next=NULL;
    struct node *iter=head;
   while (iter != NULL)
   {
       if(iter->data==valToFind)
       {
       temp->next=iter->next;
       iter->next=temp;
       break;
       }
     iter=iter->next;
   }
 }
//Delete a node from the list based upon its value.
void delete_node(struct node *head,int valToDelete)
{
    struct node *iter=head;
    struct node *nodePrev=NULL;

   while (iter != NULL)
   {
       if(iter->data==valToDelete)
       {
           nodePrev->next=iter->next;
           free(iter);
       break;
       }
       nodePrev=iter;
     iter=iter->next;
   }

 }
//traverse the list and print its elements.
 void traverse_list(struct node *head)
{
   struct node *iter=head;
   //iter !=null is satisfied when all items are read from the linked list
   while (iter != NULL)
   {
   cout<<"-->"<<iter->data;
   iter=iter->next;
   }
 }
 //Count the no of nodes in the list iteratively.
  void iter_count_list(struct node *head)
{
    int count=0;
   struct node *iter=head;
   //iter !=null is satisfied when all items are read from the linked list
   while (iter != NULL)
   {
   count++;
   iter=iter->next;
   }
   cout<<"No of nodes is: "<<count;
 }
//Count the no of nodes in the list recursively.
int rec_count_list(struct node *head)
{
if(head==NULL)
{
return 0;
}
else
{
return 1+rec_count_list(head->next);
}
}
//Reverse the link list recursively.
 void rec_rev_list(struct node **head)
{
    //8->7->6->5
    struct node *first,*rest;
    //return if list is empty
    if((*head)==NULL)
    {
    return;
    }
    first=(*head); //first=8 rest=7,6,5
    rest=(*head)->next;
    //return if there is only one item in that case 5 will be first and Rest will be null
    if(rest==NULL)
    {
    return;
    }
    rec_rev_list(&rest);
    //make rest last node of rest point to first.
    first->next->next=first;
    //insert null in next of first because it is last node now.
    first->next=NULL;
    //change the head pointer.
    (*head)=rest;
 }

//reversing link list iteratively
void iter_rev_list(struct node **head)
{
struct node *prev,*curr,*next;
prev=NULL;
curr=(*head);
next=NULL;

while(curr!=NULL)
{
    //assign next node a value
next=curr->next;
//let current point to previous so that link reverses
curr->next=prev;
//make current as previous
prev=curr;
//next as current;
curr=next;
}
//prev now contains the last node of the list.
(*head)=prev;
 }

//driver for all the functions
int main()
{
    struct node *head=NULL;
    insert_node_in_beg(&head,5);
    insert_node_in_beg(&head,6);
    insert_node_in_beg(&head,7);
    insert_node_in_beg(&head,8);
    insert_node_in_beg(&head,9);
   // insert_node_in_end(head,10);
   // insert_node_in_end(head,15);
   // insert_node_after(head,7,100);
   // delete_node(head,10);
   // delete_node(head,5);
   // rec_rev_list(&head);
   //iter_rev_list(&head);
   // traverse_list(head);
  // iter_count_list(head);
  cout<<rec_count_list(head);
    return 0;
}
