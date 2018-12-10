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
	//队列+堆栈
    //队列BFS的同时将数据记录到堆栈中，BFS时右节点优先进队
    //记录堆栈中需要记录当前层的所有节点数据与节点个数
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        stack<int> s;
        //如果输入为空
        if (root == NULL) {
            return res;
        }
        //1. 队列做BFS,右子树优先进队
        queue<TreeNode*> q;
        q.push(root);
        while( !q.empty() ){
            //获取当前层的数目
            int len = q.size();
            vector<int> level;
            TreeNode* tmp;
            for( int i = 0; i < len; i++ ){
                //取一节点放入堆栈中
                tmp = q.front();
                q.pop();
                s.push(tmp->val);
                //当前层所有的节点如果有孩子节点则压入队列
                //右子树优先入队
                if(tmp->right){
                    q.push(tmp->right);
                }
                if(tmp->left){
                    q.push(tmp->left);
                }
            }
            //记录节点的个数
            s.push(len);
        }
        
        //2. 遍历堆栈记录数据
        while( !s.empty() ){
            vector<int> level_traverse;
            int len = s.top();
            s.pop();
            for( int i = 0; i < len; i++ ){
                level_traverse.push_back(s.top());
                s.pop();
            }
            res.push_back(level_traverse);
        } 
        return res;
    }
};

/*BFS+反转法
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
            //插入头部
            res.insert(res.begin(), level);
        }
        return res;
    }
};*/