#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// INSERTION IN BST
Node* createBST(Node* root, int value) {
    if(root == NULL) {
        Node* newNode = new Node(value);
        return newNode;
    }
    if(value < root->data) {
        root->left = createBST(root->left, value);
    } else if(value > root->data) {
        root->right = createBST(root->right, value);
    }
    return root;
}

// INORDER TRAVERSAL
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// SEARCHING IN BST
bool Search(Node* root, int key) {
    if(root == NULL) return false;
    if(root->data == key) return true;
    else if(key < root->data) return Search(root->left, key);
    else return Search(root->right, key);
}

// DELETION IN BST
int Min_value(Node* root) {
    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL) return NULL;

    if(key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if(key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Case 1: No child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // Case 2: One child
        else if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Two children
        else {
            int minVal = Min_value(root->right);
            root->data = minVal;
            root->right = deleteNode(root->right, minVal);
        }
    }
    return root;
}

int main() {
    Node* root = NULL;
    int value;

    while(true) {
        cout << "ENTER VALUE (-1 TO STOP): ";
        cin >> value;
        if(value == -1) break;
        root = createBST(root, value);
    }

    cout << "\nINORDER TRAVERSAL: ";
    inorder(root);

    cout << "\n\nSearching a key";
    int key = -1;
    cout << "\nENTER THE VALUE OF KEY: ";
    cin >> key;
    cout << "FOUND: " << Search(root, key);

    cout << "\n\nDELETION";
    int delKey;
    cout << "\nENTER THE VALUE TO DELETE: ";
    cin >> delKey;
    root = deleteNode(root, delKey);
    cout << "INORDER AFTER DELETION: ";
    inorder(root);

    return 0;
}