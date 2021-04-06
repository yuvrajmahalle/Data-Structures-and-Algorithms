#include<bits/stdc++.h>
using namespace std;


// Node
class Node{
public:
	int data;
	Node *next;
};

// print circular list
void printList(Node *head){
	Node *temp_node = head;
	if (head != NULL){
		do{
			cout<<temp_node->data<<" ";
			temp_node = temp_node->next;
		}while(temp_node !=  head);
	}
}

// push new node
void push(Node **head_ref, int data){

	Node *new_node = new Node();
	Node *temp = *head_ref;

	new_node->data = data;
	new_node->next = *head_ref; // to make the linkedlist circular

	if(*head_ref != NULL){
		while(temp->next != *head_ref) temp=temp->next;
		temp->next = new_node;
	}else{
		new_node->next = new_node;
	}

	*head_ref = new_node;

}


int main(){

	Node *head = NULL;
	 
	push(&head,1);
	push(&head,6);
	push(&head,2);
	push(&head,8);
	push(&head,11);
	push(&head,5);

	printList(head);
 
}