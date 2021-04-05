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

// rotate list by making it circular and move k-1 step forward to make it NULL
// and assign the kth node as head
void rotateList(Node **head_ref,int k){
	if(k==0){
		return ;
	}

	// making list circular.
	Node *tempCurrent = *head_ref;

	while(tempCurrent->next != NULL){
		tempCurrent = tempCurrent->next;
	}

	tempCurrent->next = *head_ref;
	tempCurrent = *head_ref;

	for(int i=0;i<k-1;i++) tempCurrent = tempCurrent->next;


	*head_ref = tempCurrent->next;
	tempCurrent->next = NULL;
	

}



 
// driver code
int main(){
	Node* head = new Node();
	Node* second = new Node();
	Node* third = new Node();
	Node* fourth = new Node();

	head->data = 9;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 7;
	third->next = fourth;

	fourth->data = 1;
	fourth->next = NULL;


	int k = 2;
 
 	cout<<"Rotate list clock wise k times"<<endl;
 	rotateList(&head, k );

 	printList(head);
 
	return 0;
}