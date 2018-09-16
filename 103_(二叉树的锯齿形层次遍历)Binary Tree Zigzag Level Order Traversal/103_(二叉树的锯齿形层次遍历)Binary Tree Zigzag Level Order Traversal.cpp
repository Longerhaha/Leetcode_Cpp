/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//你可以选择使用双端队列
//也可以使用本方法
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        //基于队列做层序遍历
        queue<TreeNode*> q;
        q.push(root);
        //层序遍历的深度
        int depth = 1;
        while( !q.empty() ){
            //保存当前层遍历的结果
            vector<int> layer;
            //获取当前层的节点数目
            int lay_size = q.size();
            //遍历当前的所有层
            for( int i = 0; i < lay_size; i++ ){
                TreeNode* tmp = q.front();
                q.pop();
                //如果左右子树非空，则入队
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                //如果是奇层，则插入尾巴
                if(depth % 2 == 1)
                    layer.push_back(tmp->val);
                //如果是偶层，则插入头部
                else
                    layer.insert(layer.begin(), tmp->val);
            }
            //将当前层遍历的结果存到res里面，同时深度加1
            res.push_back(layer);
            depth += 1;
        }
        return res;
    }
};