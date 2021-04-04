#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

// print linkedlist
void printList(Node* head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void swapNodeWithoutSwappingLinks(Node **head_ref, int a, int b){

	if(a == b){
		cout<<"both the node are same!!"<<endl;
		return;
	}

	// find previous node of the swapping node for chaning reference.
 	Node *previous_node_a = new Node();
 	Node *previous_node_b = new Node();

 	Node *node_a = new Node();
 	Node *node_b = new Node();

 	Node *temp = *head_ref;
 	bool aflag = true, bflag = true;
 
///	 to get the previous node of both the input.
 	while(temp != NULL){

 		if(temp->data == a){
 			node_a = temp; // get current data node
 			aflag = false;
 		}
 		if(temp->data == b){
 			node_b = temp; // get current data node
 			bflag = false;
 		}

 		if(!aflag){
 			previous_node_a = temp;  // get previous node
 			//aflag= true;
 		}

 		if(!bflag){
 			previous_node_b = temp; // get previous node
 			//bflag= true;
 		}
 		if(!aflag && !bflag) break; 
 		 		 
 		temp = temp->next; // increment the temp 
 	}
 
 	// chaning the reference of the previous nodes
 	Node *temp_previous = previous_node_a;
 	previous_node_a->next = previous_node_b->next;
 	previous_node_b->next = temp_previous->next;

// chaning the reference of the current nodes
 	Node *temp_current_node = node_a;
 	node_a->next = node_b->next;
 	node_b->next = temp_current_node->next;
 
}


// swap 2 with 4
int main(){
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 4;
	fourth->next = NULL;
 
	swapNodeWithoutSwappingLinks(&head,2,4);
	printList(head);

	return 0;
}