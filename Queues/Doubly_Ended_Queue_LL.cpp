#include<iostream>
using namespace std;

// Doubly Ended Queue using doubly linked list

struct Node {
    int data;
    Node* next;
    Node* prev;
};

int MAX = 100;
int size = 0;

Node* front = NULL;
Node* rear = NULL;

bool isFull() {
    return size == MAX;
}

bool isEmpty() {
    return size == 0;
}

void Insert_front(int val) {

    if(isFull()) {
        cout << "Full Queue\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(size == 0) {
        front = rear = newNode;
    }
    else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }

    size++;
}

void Insert_rear(int val) {

    if(isFull()) {
        cout << "Full Queue\n";
        return;
    }

    Node* newNode = new Node();

    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(size == 0) {
        front = rear = newNode;
    }
    else {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }

    size++;
}

void Delete_front() {

    if(isEmpty()) {
        cout << "Empty Queue\n";
        return;
    }

    if(front == rear) {
        delete front;
        front = rear = NULL;
    }
    else {
        Node* temp = front;
        front = front->next;
        front->prev = NULL;
        delete temp;
    }

    size--;
}

void Delete_rear() {

    if(isEmpty()) {
        cout << "Empty Queue\n";
        return;
    }

    if(front == rear) {
        delete rear;
        front = rear = NULL;
    }
    else {
        Node* temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        delete temp;
    }

    size--;
}

void display() {

    Node* temp = front;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    Insert_front(10);
    Insert_front(20);

    Insert_rear(30);
    Insert_rear(40);

    display();

    Delete_front();

    display();

    Delete_rear();

    display();
}