#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// INSERTION IN BINARY TREE
Node* createBST(Node* root, int value)
{
    // Base case
    if(root == NULL)
    {
        Node* newNode = new Node(value);
        return newNode;
    }

    // Insert in left subtree
    if(value < root->data)
    {
        root->left = createBST(root->left, value);
    }

    // Insert in right subtree
    else if(value > root->data)
    {
        root->right = createBST(root->right, value);
    }

    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// SEARCHING IN BST

  bool Search(Node*root,int key){
    if(root == NULL){
        return false;
    }

    if(root->data == key){
        return true;
    }
    else if(key<root->data){
        return Search(root->left,key);
    }
    else{
        return Search(root->right,key);
    }
    
  }

int main()
{
    Node* root = NULL;

    int value;

    while(true)
    {
        cout << "ENTER VALUE (-1 TO STOP): ";
        cin >> value;

        if(value == -1)
            break;

        root = createBST(root, value);
    }

    cout << "Searching a key\n";
    int key = -1;
    cout<< "ENTER THE VALUE OF KEY: ";
    cin >> key;
    cout << Search(root,key);


    cout << "\nINORDER TRAVERSAL: ";
    inorder(root);

    return 0;
}