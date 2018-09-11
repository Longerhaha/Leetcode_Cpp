/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
class Solution {
public:
    typedef vector<int>::iterator Iter;
    TreeNode* buildTree_recurse(Iter preoroder_begin, int pre_len, Iter inorder_begin, int in_len){
        if(pre_len == 1){
            return (new TreeNode(*preoroder_begin));
        }
        
        TreeNode* root = new TreeNode(*preoroder_begin);
        
        
        int i;
        for( i = 0; i < in_len; i++ ){
            if(*(inorder_begin + i) == *preoroder_begin)
                break;
        }

        
        if(i == 0)
            root->left = nullptr;
        else
            root->left = buildTree_recurse(preoroder_begin + 1, i, inorder_begin, i);
        
        
        if(i == in_len - 1)
            root->right = nullptr;
        else
            root->right = buildTree_recurse(preoroder_begin + i + 1, pre_len - (i + 1), inorder_begin + i + 1, in_len - (i + 1));
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return nullptr;
        else
            return buildTree_recurse(preorder.begin(), preorder.size(), inorder.begin(), inorder.size());
    }
};*/


class Solution {
public:
    typedef vector<int>::iterator Iter;
    //基于递归形式的前序与中序遍历序列构造二叉树
    TreeNode* buildTree_recurse(Iter preoroder_begin, Iter preoroder_end, Iter inorder_begin, Iter inorder_end){
        //如果只有一个节点
        if(preoroder_begin == preoroder_end - 1){
            return (new TreeNode(*preoroder_begin));
        }
        //先建立根节点
        TreeNode* root = new TreeNode(*preoroder_begin);
        //根据先序遍历结果找到其在中序遍历结果中的指针位置
        Iter div = find(inorder_begin, inorder_end, *preoroder_begin);
        //如果没有左子树
        if(div == inorder_begin)
            root->left = nullptr;
        //否则递归左子树
        else
            root->left = buildTree_recurse(preoroder_begin + 1, preoroder_begin + 1 + (div - inorder_begin), inorder_begin, div);
        //如果没有右子树
        if(div == inorder_end - 1)
            root->right = nullptr;
        //否则递归右子树
        else
            root->right = buildTree_recurse(preoroder_begin + (div - inorder_begin) + 1, preoroder_end, inorder_begin + (div - inorder_begin) + 1, inorder_end);
        //返回根节点
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //如果输入为空，则返回空
        if(preorder.size() == 0)
            return nullptr;
        else
            return buildTree_recurse(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};