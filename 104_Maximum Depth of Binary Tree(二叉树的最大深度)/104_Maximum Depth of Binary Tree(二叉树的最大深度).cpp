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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        //初始化深度为0
        int depth = 0;
        //将头结点压入队列
        if(root) 
            q.push(root);
        //利用队列做二叉树的层次遍历
        while( !q.empty() ){
            //深度加1
            depth += 1;
            //获取当前层的深度
            int layer_len = q.size();
            //层次遍历的所有节点
            //如果该节点有孩子节点，则入队
            for( int i = 0; i < layer_len; i++ ){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                
                if(tmp->right)
                    q.push(tmp->right);
            }
        }
        return depth;
    }
};