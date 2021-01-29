#include <bits/stdc++.h>
using namespace std;

//  for printing the Tree in graphical way
#define GLOBALSPACE 5

//  Node class
class Node
{
public:
    int key;
    Node *left, *right;

    Node()
    {
        key = 0;
        left = right = NULL;
    }
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// Binary Search Tree class
class BinarySearchTree
{
private:
    Node *root;

public:
    // constructor
    BinarySearchTree()
    {
        root = NULL;
    }

    // function to check if the binary tree is empty
    bool isEmpty()
    {
        if (root == NULL)
            return true;
        return false;
    }

    // INSERTIONS

    // function to insert Node into BinarySearchTree Iterative
    void insertNode(int key)
    {

        Node *new_node = new Node(key);
        Node *temp = root;

        // checking if Binary Search Tree is empty
        if (isEmpty())
        {
            root = new_node;
            return;
        }

        // if Binary Search Tree is not empty
        while (temp != NULL)
        {
            // checking or duplicate values
            if (new_node->key == temp->key)
            {
                cout << "Duplication not allowed" << endl;
                return;
            }
            // checking if value is less than root
            else if (new_node->key < temp->key && temp->left == NULL)
            {
                temp->left = new_node;
                return;
            }
            else if (new_node->key < temp->key)
            {
                temp = temp->left;
            }
            // checking if value is greater than root
            else if (new_node->key > temp->key && temp->right == NULL)
            {
                temp->right = new_node;
                return;
            }
            else if (new_node->key > temp->key)
            {
                temp = temp->right;
            }
        }
        return;
    }

    // function to insert Node into BinarySearchTree Recursively
    void insertNodeRecursive(Node *rootNode, int data)
    {
        Node *temp = rootNode;
        // if the root node does not exist, new node will be root node
        if (!temp)
        {
            Node *new_node = new Node(data);
            rootNode = new_node;
            return;
        }
        else
        {
            if (data > temp->key)
            {
                if (temp->right == NULL)
                {
                    Node *new_node = new Node(data);
                    temp->right = new_node;
                    return;
                }
                else
                    insertNodeRecursive(temp->right, data);
            }
            else if (data < temp->key)
            {
                if (temp->left == NULL)
                {
                    Node *new_node = new Node(data);
                    temp->left = new_node;
                    return;
                }
                else
                    insertNodeRecursive(temp->left, data);
            }
            else
            {
                cout << "Duplicate Data not allowed" << endl;
                return;
            }
        }
        return;
    }

    // TRAVERSALS

    // inorder traversal (recursive)
    void inorderTraversal(Node *treeNode)
    {
        if (!treeNode)
            return;
        inorderTraversal(treeNode->left);
        cout << treeNode->key << " ";
        inorderTraversal(treeNode->right);
    }

    // preorder traversal (recursive)
    void preorderTraversal(Node *treeNode)
    {
        if (!treeNode)
            return;
        cout << treeNode->key << " ";
        preorderTraversal(treeNode->left);
        preorderTraversal(treeNode->right);
    }

    // postorder traversal
    void postorderTraversal(Node *treeNode)
    {
        if (!treeNode)
            return;
        postorderTraversal(treeNode->left);
        postorderTraversal(treeNode->right);
        cout << treeNode->key << " ";
    }

    // printing the tree in a graphical way
    void printTree(Node *treeNode, int space)
    {
        // if tree is empty
        if (treeNode == NULL)
            return;

        // adding space
        space = space + GLOBALSPACE;
        printTree(treeNode->right, space);
        cout << endl;
        for (int i = GLOBALSPACE; i < space; i++)
        {
            cout << " ";
        }
        cout << treeNode->key << endl;
        printTree(treeNode->left, space);
    }

    // SEARCHING IN BINARY TREE SEARCH

    // recursive function to search element in binary search tree
    bool searchElement(Node *treeNode, int element)
    {
        Node *temp = treeNode;
        if (temp == NULL)
            return false;

        while (temp != NULL)
        {
            if (temp->key == element)
                return true;
            else if (temp->key > element)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }

    // function to find the height of binary search tree
    int bst_height(Node *treeNode)
    {
        // if tree is empty
        if (treeNode == NULL)
            return -1;
        int lheight = bst_height(treeNode->left);
        int rheight = bst_height(treeNode->right);
        int height = max(lheight, rheight) + 1;
        return height;
    }

    // LEVEL ORDER TRAVERSAL (BFS)
    void printBFS(Node *treeNode)
    {
        int height = bst_height(treeNode);
        for (int i = 0; i <= height; i++)
            printlevel(treeNode, i);
    }
    void printlevel(Node *treeNode, int level)
    {
        if (treeNode == NULL)
        {
            return;
        }
        else if (level == 0)
        {
            cout << treeNode->key << " ";
        }
        else
        {
            printlevel(treeNode->left, level - 1);
            printlevel(treeNode->right, level - 1);
        }
    }

    // function to return the Root Node of the Binary Search Tree
    Node *
    getRoot()
    {
        return root;
    }
};

int main()
{
    BinarySearchTree bst;
    bst.insertNode(25);
    bst.insertNode(20);
    bst.insertNode(30);
    bst.insertNodeRecursive(bst.getRoot(), 35);
    bst.insertNodeRecursive(bst.getRoot(), 10);

    cout << "Inorder Traversal: " << endl;
    bst.inorderTraversal(bst.getRoot());
    cout << "\nPreorder Traversal: " << endl;
    bst.preorderTraversal(bst.getRoot());
    cout << "\nPostorder Trvaersal: " << endl;
    bst.postorderTraversal(bst.getRoot());

    cout << "\nGraphical Representation of Tree: " << endl;
    bst.printTree(bst.getRoot(), 5);

    if (bst.searchElement(bst.getRoot(), 35))
        cout << "Element found." << endl;
    else
        cout << "Element not found." << endl;

    cout << "Height of BST: " << bst.bst_height(bst.getRoot()) << endl;

    cout << "Level order Traversal: " << endl;
    bst.printBFS(bst.getRoot());
    return 0;
}