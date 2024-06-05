/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 检查根部是否相等，不相等直接返回false
    注意空树
    相等则比较左的左vs右的右--左的右vs右的左
 */
bool checkSubTree(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)
        return true;
    if (left == nullptr ^ right == nullptr)
        return false;
    if (left->val != right->val)
        return false;

    return checkSubTree(left->left, right->right) && checkSubTree(left->right, right->left);
}

bool checkSymmetricTree(TreeNode *root)
{
    if (root == nullptr)
        return true;
    return checkSubTree(root->left, root->right);
}
