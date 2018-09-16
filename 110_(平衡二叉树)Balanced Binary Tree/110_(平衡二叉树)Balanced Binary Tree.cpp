/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int depth_dfs(TreeNode* root){
        //如果输入为空指针，返回深度0
        if(root == nullptr)
            return 0;
        //求左子树的长度与右子树的长度
        int left_depth = depth_dfs(root->left);
        int right_depth = depth_dfs(root->right);
        //如果左子树不平衡、右子树不平衡或者他自己不平衡，返回-1
        if(left_depth == -1 || right_depth == -1 || abs(left_depth - right_depth) > 1)
            return -1;
        //否则获取该根节点的深度
        else
            return max(left_depth, right_depth) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return (depth_dfs(root) != -1);
    }
};