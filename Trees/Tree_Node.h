// Implementation of Node for a Generic Tree.
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode *> children;

    TreeNode(T data)
    {
        this->data = data;
    }
    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            // deleting each child of the node first and then deleting the node itself.
            delete children[i];
        }
    }
};