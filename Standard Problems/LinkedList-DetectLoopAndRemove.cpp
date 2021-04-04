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

// detect loop using hashing method
// store all the address in the unordered_set and check if the next address is already present in hash or not.
// if yes, cycle is present in the linkedlist else no cycle(Loop).
bool detectLoopAndRemoveIt(Node *head){
	unordered_set<Node*> s;
	while(head!=NULL){
		if(s.find(head) != s.end()) return true;

		s.insert(head);

		head = head->next;

	}
	return false;
}

bool floydCycleFindingAlgo(Node *head){
	// floyd cycle finding algo 
 	// uses two pointer to detect cycle, fast and slow pointer
 	// fast pointer will traverse two node 
 	// slow pointer will traverse single node at a time.

	// create two pointer
	Node *slow = head;
	Node *fast = head;

	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if(fast == slow){
			return true;
		}
	}
	return false;
}


bool removeCycleUsingFloydAlgo(Node *head){
	// floyd cycle finding algo 
 	// uses two pointer to detect cycle, fast and slow pointer
 	// fast pointer will traverse two node 
 	// slow pointer will traverse single node at a time.

	// create two pointer
	Node *slow = head;
	Node *fast = head;

	//
	while(slow && fast && fast->next){
		slow = slow->next;
		fast = fast->next->next;

		if(fast == slow){

			slow->next = NULL; // this flag will set the next address to null (last node) to remove the cycle

			return true;
		}
	}
	return false;
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
	fourth->next = second;
 
	bool loopStatus = detectLoopAndRemoveIt(head);
	if(loopStatus){
		cout<<"Cycle detected"<<endl;
	}else{
		cout<<"Cycle not detected"<<endl;
	}

	bool loopStatusFloyd = floydCycleFindingAlgo(head);
	if(loopStatusFloyd){
		cout<<"Cycle detected"<<endl;
	}else{
		cout<<"Cycle not detected"<<endl;
	}

	
	bool loopRemoveStatusFloyd = removeCycleUsingFloydAlgo(head);
	if(loopRemoveStatusFloyd){
		cout<<"Cycle detected and removed"<<endl;
	}else{
		cout<<"Cycle not detected"<<endl;
	}

	printList(head);

	return 0;
}