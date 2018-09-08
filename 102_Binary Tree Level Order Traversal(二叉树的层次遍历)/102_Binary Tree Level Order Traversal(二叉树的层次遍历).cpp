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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        //如果输入为空
        if (root == NULL) {
            return res;
        }
        //队列做BFS
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ){
            //获取当前层的数目
            int len = q.size();
            vector<int> level;
            TreeNode* tmp;
            for( int i = 0; i < len; i++ ){
                //取一节点放入当前层的结果矢量里
                tmp = q.front();
                q.pop();
                level.push_back(tmp->val);
                //当前层所有的节点如果有孩子节点则压入队列
                if(tmp->left){
                    q.push(tmp->left);
                }
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};