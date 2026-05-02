#include<iostream>
using namespace std;

int  MAX=100;
int arr[100];

int front =-1;
int rear = -1;
int size =0;

void Enqueue(int value){
    if(size>=MAX){
        cout << "THE QUEUE IS FULL";
    }
    if(size == 0){
        front++;   
    }
    rear++;
    size++;
    arr[rear] = value;
    return;
}

void Dequeue(){
    if(size ==0){
        cout << "THE QUEUE IS EMPTY";
    }
    front++;
}

int Peek(){
    if(size ==0){
        cout << "THE QUEUE IS EMPTY";
    }
    return arr[front];
}

void Display(){
    int i=front;
    while( i<=rear){
        cout << arr[i] << " ";
        i++;
    }
}


int main(){

   Enqueue(12);
   Enqueue(13);
   Enqueue(14);
   Enqueue(15);
   Enqueue(17);
   Enqueue(19);
   Dequeue();
   Dequeue();
   cout << Peek() << "\n";
   Display();


}