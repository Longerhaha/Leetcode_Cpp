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
    typedef vector<int>::iterator Iter; 
    TreeNode* sortedArrayToBST_recurse(Iter begin, Iter end){
        //如果输入的指针一致，则返回空
        if(begin == end)
            return nullptr;
        //找到中间节点
        Iter mid = begin + (end - begin) / 2;
        //生成以中间节点为根节点的树
        TreeNode* root = new TreeNode(*mid);
        //递归左子树
        root->left = sortedArrayToBST_recurse(begin, mid);
        //递归右子树
        root->right = sortedArrayToBST_recurse(mid + 1, end);
        //返回根节点
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_recurse(nums.begin(), nums.end());
    }
};