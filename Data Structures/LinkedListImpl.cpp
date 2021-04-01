#include<bits/stdc++.h>
using namespace std;

// node for storing data and next node reference
class Node{
	public:
		int data;
		Node* next;
};

// method to print linkedlist.
void printLinkedList(Node* n){
	cout<<"Traverse LinkedList "<<endl;
	while(n != NULL){
		cout<<n->data<<" ";
		n = n->next;
	}
}

// driver code
int main(){
	Node* first = NULL; // head node
	Node* second = NULL;
	Node* third = NULL; // last node

	first = new Node();
	second = new Node();
	third = new Node();

	first->data = 1;
	first->next = second; // passing reference of second to first ...

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	printLinkedList(first);

	return 0;
}