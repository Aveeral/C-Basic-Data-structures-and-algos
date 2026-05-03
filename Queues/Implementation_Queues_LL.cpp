#include<iostream>
using namespace std;

// Queue Implementation Using Linked List

struct Node {
    int data;
    Node* next;
};

int MAX = 100;

Node* front = NULL;
Node* rear = NULL;

int size = 0;

bool isFull() {
    return size == MAX;
}

bool isEmpty() {
    return size == 0;
}

void Enqueue(int value) {

    if(isFull()) {
        cout << "THE QUEUE IS ALREADY FULL\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    // First node
    if(size == 0) {
        front = rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

void Dequeue() {

    if(isEmpty()) {
        cout << "THE QUEUE IS ALREADY EMPTY\n";
        return;
    }

    // Only one node
    if(front == rear) {
        delete front;
        front = rear = NULL;
    }
    else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    size--;
}

int Peek() {

    if(isEmpty()) {
        return -1;
    }

    return front->data;
}

void Display() {

    if(isEmpty()) {
        cout << "QUEUE IS EMPTY\n";
        return;
    }

    Node* temp = front;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Enqueue(12);
    Enqueue(13);
    Enqueue(14);
    Enqueue(15);
    Enqueue(16);
    Enqueue(17);

    Dequeue();
    Dequeue();

    cout << "SIZE: " << size << endl;

    cout << "FRONT ELEMENT: " << Peek() << endl;

    Display();

    return 0;
}