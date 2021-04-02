#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};


void printList(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

// adding node at front TC (O(1))
void addAtFront(Node** head, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head);
	(*head) = new_node;
}

// adding to certain position TC (O(n)) for position searching and O(1) for insertion
void addAtGivenPosition(Node* head, int position, int position_data){
	int position_counter = 0;
	Node* prev_node = new Node();
	Node* new_node = new Node();
	
	while(head!=NULL){
		if(position_counter==position){
			new_node->data = position_data; // inserting new node data
			new_node->next = prev_node->next; // reassign to previous node reference to new node next.
			prev_node->next = new_node; // assing new node to previous node. 
			//break;
		}	
		position_counter++;
		prev_node = head;
		head = head->next;
	}
}

//adding end of the linkedlist
void addEndOfList(Node** head, int end_node_data){
	Node* new_node = new Node();
	Node* lastAddres = *head;

	new_node->data = end_node_data;
	new_node->next = NULL;

	if(*head == NULL){
		*head = new_node;
		return;
	}
		
	while (lastAddres->next != NULL)  
		lastAddres = lastAddres->next;   
		
	lastAddres->next = new_node;

	return;
}

int main(){

	Node* first = NULL;
	Node* second = NULL;
	Node* third = NULL;

	first = new Node();
	second = new Node();
	third = new Node();

	first->data = 1;
	first->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	printList(first);

// adding at front
	cout<<"Adding at front"<<endl;
	int new_data = 10;
	addAtFront(&first,new_data);
	printList(first);

// adding at given position
	cout<<"Adding at given position"<<endl;
	int position = 1;
	int position_data = 5;
	addAtGivenPosition(first,position,position_data);
	printList(first);

// adding at given position
	cout<<"Adding at end"<<endl;
	int end_node_data = 8;
	addEndOfList(&first,end_node_data);
	printList(first);

	return 0;
}