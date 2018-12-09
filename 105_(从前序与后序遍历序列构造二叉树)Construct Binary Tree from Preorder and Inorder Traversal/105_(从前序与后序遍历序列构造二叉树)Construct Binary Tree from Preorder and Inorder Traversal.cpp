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
    typedef vector<int>::iterator iter;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree_recurse(preorder.begin(), preorder.size(), inorder.begin(), inorder.size());
    }
    TreeNode* buildTree_recurse(iter preorder_begin, int preorder_len, iter inorder_begin, int inorder_len){
        if(preorder_len == 0) return nullptr;
        TreeNode* root = new TreeNode(*preorder_begin);
        int i;
        for( i = 0; i < inorder_len; i++ ){
            if(*(inorder_begin + i) == *preorder_begin) break;
        }
        root->left = buildTree_recurse(preorder_begin + 1, i, inorder_begin, i);
        root->right = buildTree_recurse(preorder_begin + i + 1, preorder_len - i - 1, inorder_begin + i + 1, inorder_len - i - 1);
        return root;
    }
};