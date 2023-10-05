#include <iostream>
using namespace std;

class Node {
private:
	int SID;
	float GPA;
	Node* p_next;
public:
	void Set_SID(int x);
	void Set_GPA(float y);
	int Get_SID();
	float Get_GPA();
	void Set_Pnext(Node* p);
	Node* Get_Pnext();
	Node();
};
void Node::Set_SID(int x) {
	SID = x;
}
void Node::Set_GPA(float y) {
	GPA = y;
}
int Node::Get_SID() {
	return SID;
}
float Node::Get_GPA() {
	return GPA;
}
void Node::Set_Pnext(Node* p) {
	p_next = p;
}
Node* Node::Get_Pnext() {
	return p_next;
}
Node::Node() {
	SID = -1;
	GPA = -1;
	p_next = NULL;
}

class List {
private:
	Node* head;
public:
List();
    void PrtSID();
    void Create();
    int Lsize();
    Node* Find(int key);
    int Insert(Node* p, int idx);
    int Remove(int idx);
    void Reverse();
    void Clear();
};
List::List() {
	head = NULL;
}
void List::PrtSID() {
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->Get_SID();
		temp = temp->Get_Pnext();
	}
}
//Create function
void List::Create(){

	//Variables for holding input data
	int sid;
	float gpa;

	//Bool for detecting first node to add
	bool isFirst = true;

	//Dynamically allocate new list
	List* studentList = new List();

	//prev points to address of previous node
	Node* prev = nullptr;

	//Loop continues along as valid inputs are made
	while(cin >> sid >> gpa){
		
		//Dynamically allocate new student node pointer
		Node* studentNode = new Node();

		//Set data for new student node pointer
		studentNode->Set_SID(sid);
		studentNode->Set_GPA(gpa);

		//Set the head of list to the current student node
		head = studentNode;

		//If this is the first node, update isFirst
		if(isFirst) isFirst = false;
		
		//If this is not the first node, set the next of head to the previous node pointed at by temp
		else head->Set_Pnext(prev);

		prev = head;
	}
}

//Size function
int List::Lsize(){
	
	//int for holding size
	int size = 0;

	//Node pointer for keep track of current node
	Node* curr = head;
	
	//Traverse through list and count nodes
	while(curr != NULL){
		size++;
		curr = curr->Get_Pnext();
	}
	
	//return result
	return size;
}

//Find function
Node* List::Find(int key){

	//Node pointer for keep track of current node
	Node* curr = head;
	
	//Traverse through list
	while(curr != NULL){
		//Return head if id equals key
		if(curr->Get_SID() == key){
			return curr;
		}

		curr = curr->Get_Pnext();
	}

	return NULL;
}

//Insert function 
int List::Insert(Node* p, int idx){

	int size = Lsize();
	int currentIdx = 1;
	bool isFirst = true;

	Node* prev = nullptr;
	Node* curr = head;


	//Return -1 if idx is out of range
	if(idx < 1 || idx > size + 1) return -1;

	else{

		//Traverse through list
		while(currentIdx < idx){
			//store current head as previous for next cycle
			prev = curr;
			//advance head to next node
			curr = curr->Get_Pnext();
			//increment currentIdx
			currentIdx++;
			
			if(isFirst) isFirst = false;
		}
		
		//head should be where p should be inserted now
		//set previous node next to p if p is not being inserted at 1
		if(!isFirst) prev->Set_Pnext(p);
		//set p next to curr
		p->Set_Pnext(curr);

		//Insertion is sucessful
		return 1;
	}
}

// Remove function
int List::Remove(int idx){
	int size = Lsize();
	int currentIdx = 1;
	bool isFirst = true;

	Node* prev = nullptr;
	Node* curr = head;

	//Return -1 if idx is out of range
	if(idx < 1 || idx > size + 1) return -1;

	else{

		//Traverse through list
		while(currentIdx < idx){
			//store current head as previous for next cycle
			prev = curr;
			//advance head to next node
			curr = curr->Get_Pnext();
			//increment currentIdx
			currentIdx++;
			
			if(isFirst) isFirst = false;
		}
		
		//head should be where node should be removed now
		//set previous node next to the next of head if not removing node 1
		if(!isFirst) prev->Set_Pnext(curr->Get_Pnext());
		//If removing node 1 set, head to equal curr next 
		else head = curr->Get_Pnext();

		//Delete data at curr
		delete curr;

		//Removal is sucessful
		return 1;
	}
}

// Reverse function
void List::Reverse(){

	Node* curr = head;
	Node* prev = nullptr;
	Node* next;

	while(curr != NULL){
		//Store the next node
		next = curr->Get_Pnext();
		//set current node's next to prev
		curr->Set_Pnext(prev);
		//update-
		//prev to curr node,
		prev = curr;
		//curr to next
		curr = next;
	}
	//prev is new head
	head = prev;
}

// Clear function
void List::Clear(){
	Node* next = nullptr;

	while(head != NULL){
		//store next node
		next = head->Get_Pnext();
		//delete current head
		delete head;
		//update head
		head = next;
	}
}


int main(){

    int samsSID = 616;

    int* ptr = &samsSID;

    cout << *ptr;

    return 0;
}