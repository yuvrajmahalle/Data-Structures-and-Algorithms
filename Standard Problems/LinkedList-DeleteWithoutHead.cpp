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


// replace node with the next node.
void deleteWithoutHead(Node *nodeToDelete){
	  *nodeToDelete = *(nodeToDelete->next);
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
 
	deleteWithoutHead(third);

	printList(head);

	return 0;
}