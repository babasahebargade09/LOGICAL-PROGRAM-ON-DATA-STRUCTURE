////////////////////////////////////////////////////////////////////////////////////////
//
//	5.Write a program which remove last node from singly linear linked list.
//
////////////////////////////////////////////////////////////////////////////////////////

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;	//holds data of the node.
	Node *next; //holds address of next node in the linked list.
};


 //////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	InsertLast 
 //
 //		Parameters		:	1. struct node **head => Holds head pointer of list.
 //							2. int no			  => Holds data which is to be insert.
 //
 //		Description     :	This function inserts node at last position in linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////
int InsertLast( struct Node **head,  int no )
 {
	struct Node *newnode=NULL;
	struct Node *temp=NULL;

	//allocate memory for node
	newnode=(struct Node *)malloc(sizeof(struct Node));

	//check whether memory is allocated or not.
	if(newnode == NULL)
	{
		return -1;
	}

	//fill node with the data.
	newnode->next=NULL;
	newnode->data=no;

	//Add node at last position.

	//If list is empty.
	if(*head == NULL)
	{
		*head=newnode;
	}

	//if linked list contains at least one node.
	else
	{
		temp=*head;

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
	}
	return 1;
 }
 //////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name   :	DeleteLast 
 //
 //		Parameters		:	1. struct node **head => Holds head pointer of list.
 //
 //		Description     :	This function delete node at Last position from linked list.  
 //
 //		Returns         :	int => 1 if function succeeds, otherowise return -1.
 //
 /////////////////////////////////////////////////////////////////////////////////////////////

 int DeleteLast(struct Node **head)
 {
	struct Node *temp1=*head;
	struct Node *temp2=*head;

	if(*head == NULL)
	{
		return -1;
	}
	else if((*head)->next == NULL)
	{
		*head=NULL;
		free(*head);
	}
	else
	{
		while(temp1->next!=NULL)
		{
			temp2=temp1;
			temp1=temp1->next;
		}
		temp2->next=NULL;
		free(temp1);
	}
	return 1;
 }

 ///////////////////////////////////////////////////////////////////////////////////////////// 
 //
 //		Function Name  :	DisplayList 
 //
 //		Parameters	   :	1.struct node *head => Holds head pointer of list. 
 // 
 //		Description    :	This function displays linked list. 
 // 
 //		Returns		   :	void 
 // 
 ///////////////////////////////////////////////////////////////////////////////////////////// 
 
 void DisplayList(struct Node *head)
 {
	if(head)
	{
		while(head)
		{
			printf("|%d|->",head->data);
			head=head->next;
		}
	}
	else
	{
		printf("\n Linked list is empty.");
	}
 }
 
 
 int main()
 {
	//create pointer which holds starting address of whole linked list.
	struct Node *first=NULL;

	//call the function to add node at first position.
	InsertLast(&first,10);
	InsertLast(&first,20);
	InsertLast(&first,30);
	InsertLast(&first,40);
	InsertLast(&first,50);
	
	printf("\n\n Linked list is => ");

	//call to DisplayList function to display linked list.
	DisplayList(first);

	//call to DeleteFirst function to remove first node from linked list.
	DeleteLast(&first);

	printf("\n\n After deleting first node the linked list is => ");
	DisplayList(first);

	DeleteLast(&first);
	printf("\n\n After deleting first node the linked list is => ");
	DisplayList(first);
 
	DeleteLast(&first);
	printf("\n\n After deleting first node the linked list is => ");
	DisplayList(first);
 
	DeleteLast(&first);
	printf("\n\n After deleting first node the linked list is => ");
	DisplayList(first);
 
	DeleteLast(&first);

	printf("\n\n After deleting first node the linked list is => ");
	DisplayList(first);
 
	getch();
	return 0;
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////
 //
 //		Input Linked List :		10 20 30 40 50 
 //
 //		Output1			  :		10 20 30 40 
 //
 //		Output2			  :		10 20 30 
 //
 /////////////////////////////////////////////////////////////////////////////////////////////