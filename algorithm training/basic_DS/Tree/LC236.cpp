struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 给定二叉树，寻找最近公共祖先 */

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    /* 如果pq即在左又在右，则本结点为答案
        如果左右都不在，则不在本子树中
        如果只在左或只在右，则答案在左或右
     */
    if (root == nullptr)
        return nullptr;
    if (root == p || root == q) // 很容易遗漏，忽略也会返回nullptr
        return root;

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left != nullptr && right != nullptr)
        return root;
    else if (left != nullptr ^ right != nullptr)
        return left == nullptr ? right : left;
    else
        return nullptr;
}