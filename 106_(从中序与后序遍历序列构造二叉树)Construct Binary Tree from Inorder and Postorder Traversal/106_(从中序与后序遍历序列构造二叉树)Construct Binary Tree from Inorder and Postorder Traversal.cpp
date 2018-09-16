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
    //递归实现根据中序与后序遍历序列构造二叉树
    TreeNode* buildTree_recurse(Iter inbegin, Iter inend, Iter postbegin, Iter postend){
        //如果中序遍历的开始指针与结束指针一致则返回空
        if(inbegin == inend)
            return nullptr;
        //后序遍历的最后一个节点是根节点
        TreeNode* tmp = new TreeNode(*(postend - 1));
        //寻找后序遍历的最后一个节点在中序遍历结果的位置
        Iter mid = find(inbegin, inend, *(postend - 1));
        //递归左子树
        tmp->left = buildTree_recurse(inbegin, mid, postbegin, postbegin + (mid - inbegin));
        //递归右子树
        tmp->right = buildTree_recurse(mid + 1, inend, postbegin + (mid - inbegin), postend - 1);
        //返回根节点
        return tmp;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree_recurse(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};