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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree_recurse(inorder.begin(), inorder.size(), postorder.begin(), postorder.size());
    }
    TreeNode* buildTree_recurse(iter inorder_begin, int inorder_len, iter postorder_begin, int postorder_len){
        if(inorder_len == 0) return nullptr;
        TreeNode* root = new TreeNode(*(postorder_begin + postorder_len - 1));
        int i;
        for( i = 0; i < inorder_len; i++ ){
            if(*(inorder_begin + i) == *(postorder_begin + postorder_len - 1)) break;
        }
        root->left = buildTree_recurse(inorder_begin, i, postorder_begin, i);
        root->right = buildTree_recurse(inorder_begin + i + 1, inorder_len - i - 1, postorder_begin + i, postorder_len - i - 1);
        return root;
    }
};