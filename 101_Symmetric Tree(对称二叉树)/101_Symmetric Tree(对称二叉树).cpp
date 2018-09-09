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
    //递归较为简单，这里使用迭代的方式解决这个问题
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        //使用队列做遍历，这是也可以使用堆栈
        queue<TreeNode*> q;
        //根节点就不用判断了，直接加入左右孩子节点
        q.push(root->left);
        q.push(root->right);
        while( !q.empty() ){
            //从队列弹出两个节点
            TreeNode* tmp1 = q.front();
            q.pop();
            TreeNode* tmp2 = q.front();
            q.pop();
            //如果都是根节点，则结束本次循环
            if(tmp1 == nullptr && tmp2 == nullptr)
                continue;
            //如果不对称，则返回false
            if((tmp1 == nullptr && tmp2) || (tmp2 == nullptr && tmp1) || (tmp1->val != tmp2->val))
                return false;
            //对称入队
            q.push(tmp1->left);
            q.push(tmp2->right);
            q.push(tmp1->right);
            q.push(tmp2->left);
        }
        //都是对称的，返回真
        return true;
    }
};