// Binary Tree Implementation
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *left;
    Node *right;
    int key;

    // constructor
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// TRAVERSAL OF TREE

// inorder traversal recursively
void inorderTraversal(Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

// inorder traversal using Stack (iterative approach)
void inorder(Node *root)
{
    stack<Node *> s;
    Node *current = root;

    while (current != NULL || s.empty() == false)
    {
        // pushing all the elements of left subtree
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        // the pointer should be null at this point
        current = s.top();
        s.pop();

        // printing the value of current
        cout << current->key << " ";

        // now checking the right subtree of the node
        current = current->right;
    }
}

// preorder traversal recursively
void preorderTraversal(Node *root)
{
    if (root)
    {
        cout << root->key << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// preorder traversal using stack (iterative approach)
void preorder(Node *root)
{
    stack<Node *> s;
    Node *current = root;
    s.push(current); // pushed root node in the stack
    while (current != NULL || s.empty() == false)
    {
        current = s.top();
        s.pop();
        cout << current->key << " ";
        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
}

// postorder traversal recursively
void postorderTraversal(Node *root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->key << " ";
    }
}

// postorder traversal using stack (iterative approach)
void postorder(Node *root)
{
    stack<Node *> s;
    Node *current = root;
    Node *prev = NULL;

    while (current != NULL || s.empty() == false)
    {
        while (current != NULL)
        {
            s.push(current);
            current = current->left;
        }

        current = s.top();

        if (current->right == NULL || current->right == prev)
        {
            cout << current->key << " ";
            s.pop();
            prev = current;
            current = NULL;
        }
        else
        {
            current = current->right;
        }
    }
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(30);
    root->left->left = new Node(20);
    root->left->right = new Node(10);

    cout << "Inorder Traversal: \n";
    inorder(root);
    cout << "\nPreOrder Traversal: \n";
    preorderTraversal(root);
    cout << "\nPostOrder Traversal: \n";
    postorderTraversal(root);
    cout << endl;
    postorder(root);
    return 0;
}