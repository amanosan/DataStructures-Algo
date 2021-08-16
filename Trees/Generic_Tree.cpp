// Implementation of Generic Trees

#include <bits/stdc++.h>
#include "Tree_Node.h"
using namespace std;

// printing tree recursively depth wise.
void print_tree(TreeNode<int> *root)
{
    // edge case (and not a base case)
    if (root == NULL)
        return;

    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << "NULL" << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print_tree(root->children[i]);
    }
}

// printing the tree level wise.
void print_tree_levelwise(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << "Tree:\n";
    queue<TreeNode<int> *> nodes;
    nodes.push(root);

    while (nodes.size() != 0)
    {
        TreeNode<int> *temp = nodes.front();
        nodes.pop();
        cout << temp->data << " : ";
        for (int i = 0; i < temp->children.size(); i++)
        {
            cout << temp->children[i]->data << ", ";
            nodes.push(temp->children[i]);
        }
        cout << endl;
    }
}

// building tree recursively from user input depth wise.
TreeNode<int> *take_input()
{
    int root_data;
    cout << "Enter data:\n";
    cin >> root_data;
    TreeNode<int> *root = new TreeNode<int>(root_data);

    int n;
    cout << "Enter number of children for " << root_data << ": ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = take_input();
        root->children.push_back(child);
    }
    return root;
}

// building tree level wise from user inputs.
TreeNode<int> *take_input_levelwise()
{
    queue<TreeNode<int> *> nodes; // queue to take pending nodes
    int root_data;
    cout << "Enter Root Data: ";
    cin >> root_data;
    TreeNode<int> *root = new TreeNode<int>(root_data);

    // pushing first value in the queue
    nodes.push(root);
    while (nodes.size() != 0)
    {
        TreeNode<int> *front_node = nodes.front();
        int num_nodes;
        nodes.pop();
        cout << "Enter number of children for " << front_node->data << ": ";
        cin >> num_nodes;
        for (int i = 0; i < num_nodes; i++)
        {
            int child_data;
            cout << "Enter child number " << i << " of " << front_node->data << ": ";
            cin >> child_data;
            TreeNode<int> *child = new TreeNode<int>(child_data);
            front_node->children.push_back(child);
            nodes.push(child);
        }
    }
    return root;
}

// function to count number of nodes in the tree
int number_of_nodes(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // initially count = 1, for root.
    int count = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += number_of_nodes(root->children[i]);
    }
    return count;
}

// function to find the sum of all nodes
int sum_of_nodes(TreeNode<int> *root)
{
    if (root == NULL)
        return -1;
    int sum = 0;
    if (root != NULL)
    {
        sum += root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += sum_of_nodes(root->children[i]);
    }
    return sum;
}

// printing all nodes at level k or depth d (both are the same thing)
void print_at_depth(TreeNode<int> *root, int k)
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->data << endl;
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        print_at_depth(root->children[i], k - 1);
    }
}

// function to count number of leaf nodes
int count_leaf_nodes(TreeNode<int> *root)
{
    int count = 0;
    if (root->children.size() == 0)
    {
        return 1;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        count += count_leaf_nodes(root->children[i]);
    }
    return count;
}

// function for PREORDER TRAVERSAL
void preorder_traversal(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ", ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder_traversal(root->children[i]);
    }
}

// function for POSTORDER TRAVERSAL
void postorder_traversal(TreeNode<int> *root)
{
    if (root == NULL)
        return;

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder_traversal(root->children[i]);
    }
    cout << root->data << ", ";
}

// function to delete the tree
// this is one way, but we can also make a destructor in the class in Tree_Node.h
void delete_tree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        delete_tree(root->children[i]);
    }
    delete root;
}

int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *node2 = new TreeNode<int>(3);

    // making the connection
    // root->children.push_back(node1);
    // root->children.push_back(node2);
    // TreeNode<int> *root = take_input();
    TreeNode<int> *root = take_input_levelwise(); // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    // print_tree_levelwise(root);
    // auto num_of_nodes = number_of_nodes(root);
    // cout << "Number of nodes: " << num_of_nodes << "\n";
    // cout << "Sum of all nodes: " << sum_of_nodes(root) << "\n";
    // cout << "Number of Leaf Nodes: " << count_leaf_nodes(root) << "\n";
    cout << "\nPreOrder Traversal:\n";
    preorder_traversal(root);
    cout << "\nPostOrder Traversal:\n";
    postorder_traversal(root);

    // deleting the tree:
    // delete_tree(root);
    delete root; // calling the destructor to delete the tree.
    return 0;
}