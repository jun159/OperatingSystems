/*************************************
 * Lab 1 Exercise 2
 * Name: Luah Bao Jun
 * Matric No: A0126258A
 * Lab Group: 4
 *************************************/

#include <stdio.h>
#include <stdlib.h> //for malloc() and free()

//Declaration of a Linked List Node

typedef struct NODE{
	int data;
	struct NODE* next;
} node;

//Function Prototypes
node* insertAt(node*, int, int);
void printList(node*);
void destroyList(node*);


int main()
{
	node* myList = NULL;    //Empty List
	int pos, input;

	while (scanf("%i %i", &pos, &input) == 2){
		myList = insertAt(myList, pos, input);
	} 

	//Output code coded for you
	printf("My List:\n");
	printList(myList);

	destroyList(myList);
	myList = NULL;

	printf("My List After Destroy:\n");
	printList(myList);

	return 0;
}

//Actual Function Implementations
node* insertAt(node* head, int pos, int newData)
{
	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = newData;
	node* prev = head;
	node* curr = head;
	node* newHead;
	int currPos = 0;

	if(head != NULL) {
		while(currPos < pos && curr->next != NULL) {
			prev = curr;
			curr = curr->next;
			currPos++;
		}

		if(pos <= 0) {
			// New node to be added to head of list
			newNode->next = head;
			newHead = newNode;
		} else if(pos > currPos) {
			// New node to be added to tail of list
			curr->next = newNode;
			newNode->next = NULL;
			newHead = head; // No change to the head
		} else {
			// New node to be added to middle of list
			prev->next = newNode;
			newNode->next = curr;
			newHead = head; // No change to the head
		}
	} else {
		// Add new node to head of list
		newNode->next = head;
		newHead = newNode;
	}

	return newHead;  
}

void printList(node* head)
	//Purpose: Print out the linked list content
	//Assumption: the list is properly null terminated
{
	//This function has been implemented for you
	node* ptr = head;

	while (ptr != NULL)  {    //or you can write while(ptr)
		printf("%i ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

void destroyList(node* head)
{
	node* next;

	while(head != NULL) {
		next = head->next;
		free(head);
		head = next;
	}

	head = NULL;
}
