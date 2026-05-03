#include<iostream>
using namespace std;

// Doubly Ended Queue using Array

#define MAX 5

int dequeArr[MAX];

int front = -1;
int rear = -1;
int size = 0;

bool isFull() {
    return size == MAX;
}

bool isEmpty() {
    return size == 0;
}

// Insert at front
void Insert_front(int val) {

    if(isFull()) {
        cout << "Full Queue\n";
        return;
    }

    // First element
    if(isEmpty()) {
        front = rear = 0;
    }
    else {
        front = (front - 1 + MAX) % MAX;
    }

    dequeArr[front] = val;

    size++;
}

// Insert at rear
void Insert_rear(int val) {

    if(isFull()) {
        cout << "Full Queue\n";
        return;
    }

    // First element
    if(isEmpty()) {
        front = rear = 0;
    }
    else {
        rear = (rear + 1) % MAX;
    }

    dequeArr[rear] = val;

    size++;
}

// Delete from front
void Delete_front() {

    if(isEmpty()) {
        cout << "Empty Queue\n";
        return;
    }

    cout << dequeArr[front] << " deleted\n";

    // Only one element
    if(front == rear) {
        front = rear = -1;
    }
    else {
        front = (front + 1) % MAX;
    }

    size--;
}

// Delete from rear
void Delete_rear() {

    if(isEmpty()) {
        cout << "Empty Queue\n";
        return;
    }

    cout << dequeArr[rear] << " deleted\n";

    // Only one element
    if(front == rear) {
        front = rear = -1;
    }
    else {
        rear = (rear - 1 + MAX) % MAX;
    }

    size--;
}

// Display deque
void display() {

    if(isEmpty()) {
        cout << "Empty Queue\n";
        return;
    }

    int i = front;

    while(true) {

        cout << dequeArr[i] << " ";

        if(i == rear) {
            break;
        }

        i = (i + 1) % MAX;
    }

    cout << endl;
}

