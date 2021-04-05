#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
};

// main logic 
void AddTwoNumbersRepresentedByLinkedList(Node* head, Node* head_1){
	
	int listOneNumber = 0, listTwoNumber = 0;
	while(head != NULL){ // generate number by traverse the list
		 
		int tempdata = head->data;
		listOneNumber *= 10;
		listOneNumber += tempdata;
		head= head->next;
	}
	 
	while(head_1 != NULL){ // same setup as above for second node
		int tempdata = head_1->data;
		listTwoNumber *= 10;
		listTwoNumber += tempdata;
		 
		head_1 = head_1->next;
	}

	cout<<listOneNumber+listTwoNumber; // print the addittion

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

	Node* head_1 = new Node();
	Node* second_1 = new Node();
	Node* third_1 = new Node();
	Node* fourth_1 = new Node();

	head_1->data = 3;
	head_1->next = second_1;

	second_1->data = 8;
	second_1->next = third_1;

	third_1->data = 2;
	third_1->next = fourth_1;

	fourth_1->data = 6;
	fourth_1->next = NULL;
 
 	AddTwoNumbersRepresentedByLinkedList(head,head_1);
 
	return 0;
}