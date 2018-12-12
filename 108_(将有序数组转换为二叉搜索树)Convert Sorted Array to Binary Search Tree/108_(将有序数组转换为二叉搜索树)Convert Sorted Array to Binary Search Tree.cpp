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
    //涉及的概念
    //vector<int> 可以理解为一个长度可变的 int 数组 
    //vector<int>::iterator 可以理解为长度可变的 int 数组的指针
    //TreeNode* root = new TreeNode(val) root 是从堆中生成一个值为 val 的链表节点的指针
    //root->left 是 root 所指向节点的左子树根节点的指针, root->right 同理
    
    typedef vector<int>::iterator iter;
public:
    //采用递归的思路
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_recurse(nums.begin(), nums.size());
    }
    //采用递归的思路
    TreeNode* sortedArrayToBST_recurse(iter begin, int len){
        //边界情况
        if(len == 0) return nullptr;
        if(len == 1) return new TreeNode(*begin);
        //找到根节点，然后左右递归
        //左子树长度为 len / 2 
        //右子树长度是 len - len / 2 - 1
        TreeNode* root = new TreeNode(*(begin + len / 2));
        root->left = sortedArrayToBST_recurse(begin, len / 2);
        root->right = sortedArrayToBST_recurse(begin + len / 2 + 1, len - len / 2 - 1);
        return root;
    } 
};