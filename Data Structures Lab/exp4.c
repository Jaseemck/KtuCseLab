//S3 Datastructures Lab
//Experiment 1
/*
Implementation of various linked list operations
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

void display(struct node* head)
{
      struct node *temp = head;
      printf("\n\nList elements are - \n");
      while(temp != NULL)
      {
   printf("%d --->",temp->data);
   temp = temp->next;
      }
}

void insertAtMiddle(struct node *head, int position, int value) {
    struct node *temp = head;
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    
    int i;

    for(i=2; inext != NULL) {
        temp = temp->next;
        }
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtFront(struct node** headRef, int value) {
    struct node* head = *headRef;
    
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    
    *headRef = head;
}

void insertAtEnd(struct node* head, int value){
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;
    
    struct node *temp = head;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromFront(struct node** headRef){
    struct node* head =  *headRef;
    head = head->next;
    *headRef = head;
}

void deleteFromEnd(struct node* head){
    struct node* temp = head;
    while(temp->next->next!=NULL){
      temp = temp->next;
    }
    temp->next = NULL;
}

void deleteFromMiddle(struct node* head, int position){
    struct node* temp = head;
    int i;
    for(i=2; inext != NULL) {
    temp = temp->next;
    }
}

temp->next = temp->next->next;
}

int main() {
  /* Initialize nodes */
  struct node *head;
  struct node *one = NULL;
  struct node *two = NULL;
  struct node *three = NULL;

  /* Allocate memory */
  one = malloc(sizeof(struct node));
  two = malloc(sizeof(struct node));
  three = malloc(sizeof(struct node));

  /* Assign data values */
  one->data = 1;
  two->data = 2;
  three->data = 3;

  /* Connect nodes */
  one->next = two;
  two->next = three;
  three->next = NULL;

  /* Save address of first node in head */
  head = one;

  display(head); // 1 --->2 --->3 --->     

  insertAtFront(&head, 4);
  display(head); // 4 --->1 --->2 --->3 --->     

  deleteFromFront(&head);
  display(head); // 1 --->2 --->3 ---> 

  insertAtEnd(head, 5);
  display(head); // 1 --->2 --->3 --->5 --->   

  deleteFromEnd(head);
  display(head); // 1 --->2 --->3 --->       

  int position = 3;
  insertAtMiddle(head, position, 10);
  display(head); // 1 --->2 --->10 --->3 --->      

  deleteFromMiddle(head, position);
  display(head); // 1 --->2 --->3 --->     
}
