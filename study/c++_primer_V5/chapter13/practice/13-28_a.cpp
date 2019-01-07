/*======================================================================
*        filename: 13-28_a.cpp
*        author: rambogui
*        data: 2019-01-07 13:32:41
======================================================================*/

#include <iostream>
#include <string>

using std::string;
using std::endl;
using std::cout;
using std::cin;

class TreeNode {
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;

public:
    TreeNode(const string & = string(), int = 0, 
        TreeNode * = NULL, TreeNode * = NULL);
    TreeNode(const TreeNode &);
    TreeNode &operator=(const TreeNode &);
    ~TreeNode();
};

TreeNode::TreeNode(const string &vstr, int cnt,
    TreeNode *lp, TreeNode *rp) : value(vstr), count(cnt),
    left(NULL), right(NULL)
{
    if (lp != NULL)
        left = new TreeNode(*lp);
    if (rp != NULL)
        right = new TreeNode(*rp);
}

TreeNode::TreeNode(const TreeNode &tn) : value(tn.value), 
    count(tn.count), left(NULL), right(NULL)
{
    if (tn.left != NULL)
        left = new TreeNode(*tn.left);
    if (tn.right != NULL)
        right = new TreeNode(*tn.right);
}

TreeNode::~TreeNode()
{
    if (left)
        delete left;
    if (right)
        delete right;
}

int main(int argc, char *argv[])
{

    return 0;
}
