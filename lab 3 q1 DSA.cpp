#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node* next;
	
};
class circularqueue{
	node* front;
	node* rear;
	
	public:
		circularqueue(){
			front = NULL;
			rear = NULL;
		}
	void enqueue(int val){
		node* newnode = new node;
		newnode->data = val;
		
		if(front==NULL){
			front = newnode;
			rear = newnode;
			rear->next = front;
			
		}
		else{
			newnode->next=front;
			rear->next = newnode;
			rear = newnode;
		}
	}
	void dequeue(){
		if (front == NULL){
			cout<<"queue is empty"<<endl;
		}
		else if (front == rear){
			node* temp = front;
			front = NULL;
			rear = NULL;
			
			delete temp;
		}
		else{
			node* temp = front;
			front = front->next;
			rear->next = front;
			
			delete temp;
		}
	}
	void display() {

    if (front == NULL) {

        cout<<"the queue is empty"<<endl;
    }
    else {
        node* temp = front;

     do {
            cout << temp->data << endl;
            temp = temp->next;

        } while (temp != front);
    
} }
   };
int main() {
    circularqueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: " << endl;
    q.display();

    q.dequeue();

    cout << "After dequeue: " << endl;
    q.display();

    return 0;
}
