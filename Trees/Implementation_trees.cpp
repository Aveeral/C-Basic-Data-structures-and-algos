// Binary Tree Implementation 
#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* right;
    Node* left;
};

Node* createTree() {
    int value = -1;
    cout << "ENTER THE DATA(-1 FOR NO NODE) OF NODE: ";
    cin >> value;
    if(value == -1){
        return NULL;
    }

    Node* newnode = new Node();

    newnode->data = value;

    cout << "ENTER THE VALUE OF LEFT NODE: ";
    newnode->left = createTree();

    cout<< "ENTER THE VALUE OF RIGHT NODE: ";
    newnode->right = createTree();

    return newnode;
    

}

void Inorder(Node* root) {
    if(root == NULL){
        return;
    }
     Inorder(root->left);
     cout << root-> data << " ";
     Inorder(root->right);
}

int main(){
    Node* root = NULL;
    root = createTree();
    Inorder(root);
}
