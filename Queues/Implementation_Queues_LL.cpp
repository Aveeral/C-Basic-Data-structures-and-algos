#include<iostream>
using namespace std;

// Implementation Using Linked List 

struct Node {
    int data;
    Node* next;
};

int MAX = 100;
Node* front = NULL;
Node* rear = NULL;
int size =0;

bool isFull(){
    if(size == MAX){
        return true;
    }
    return false;
}
bool isEmpty(){
    if(size == 0){
        return true;
    }
    return false;
}

void Enqueue(int value){
    if(isFull()){
        cout << "THE QUEUE IS ALREADY FULL";
    }
    Node* newNode = new Node();
    newNode->data = value;
    if(size == 0){ 
       front = newNode;
       rear = newNode;
    }

    rear->next = newNode;
    rear = newNode;
    size++;
    return;
}

void Dequeue(){
    if(isEmpty()){
        cout << "THE QUEUE IS ALREADY EMPTY";
    }
    Node* temp = front;
    front = temp->next;
    delete temp;
    size--;
    return;
}

int Peak(){
    if(isEmpty()){
        return -1;
    }
    return front->data;
}

void Display(){
    Node* temp = front;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}

int main(){

    Enqueue(12);
    Enqueue(13);
    Enqueue(14);
    Enqueue(15);
    Enqueue(16);
    Enqueue(17);
    Dequeue();
    Dequeue();
    
    cout << size << "\n";
    Display();
    


}