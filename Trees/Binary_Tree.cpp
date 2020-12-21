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

// CREATION OF TREE

// recursive function to create a tree
Node *preorderBuildTree() // it will return the root node of the tree.
{
    int key;
    cin >> key;
    if (key == -1)
        return NULL;
    Node *root = new Node(key);
    root->left = preorderBuildTree();
    root->right = preorderBuildTree();
    return root;
}

// INSERTION IN TREE

// function to insert a node according to level order
void insertLevelOrder(Node *root, int data)
{
    Node *new_node = new Node(data);
    if (root == NULL)
    {
        root = new_node;
        return;
    }

    // traversing till we find suitable place to insert
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *temp = q.front();
        q.pop();

        // checking for left node
        if (temp->left != NULL)
            q.push(temp->left);
        else
        {
            temp->left = new_node;
            return;
        }
        // checking for right tree
        if (temp->right != NULL)
            q.push(temp->right);
        else
        {
            temp->right = new_node;
            return;
        }
    }
}

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

//  Height of tree
int heightRecursive(Node *root)
{
    if (root == NULL)
        return 0;
    int heightLST = heightRecursive(root->left);
    int heightRST = heightRecursive(root->right);
    int height = max(heightLST, heightRST) + 1;
    return height;
}

// LEVEL ORDER TRAVERSAL

// using recursion
void printLevel(Node *root, int level)
{
    // empty tree
    if (root == NULL)
        return;

    // tree with height 1 (just the root node)4
    if (level == 1)
    {
        cout << root->key << " ";
        return;
    }
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrderRecursive(Node *root)
{
    int height = heightRecursive(root);
    for (int i = 1; i <= height; i++)
    {
        printLevel(root, i);
    }
}

// using queue
void levelOrderTraversal(Node *root)
{
    // checking if tree is empty
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *temp = q.front();
        cout << temp->key << " ";
        q.pop();

        // checking for left node
        if (temp->left != NULL)
            q.push(temp->left);
        // checking for right node
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{
    Node *root = preorderBuildTree(); // input to be given in preorder notation
    // Input: 3 4 -1 6 -1 -1 5 1 -1 -1 -1
    // Input: 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    // Input: 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    cout << "Inorder Traversal: \n";
    inorder(root);
    cout << "\nPreOrder Traversal: \n";
    preorderTraversal(root);
    cout << "\nPostOrder Traversal: \n";
    postorderTraversal(root);
    cout << "\nLevel Order Traversal using Queue: \n";
    levelOrderTraversal(root);
    insertLevelOrder(root, 6); // inserting 6 to the tree.
    cout << "\nLevel Order Traversal using Recursion: \n";
    levelOrderRecursive(root);
    cout << "\nHeight of Tree: " << heightRecursive(root);
    cout << "\nNodes in Level 3: ";
    printLevel(root, 3);
    return 0;
}