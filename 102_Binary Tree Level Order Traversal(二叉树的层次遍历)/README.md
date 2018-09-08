# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 102_Binary Tree Level Order Traversal(二叉树的层次遍历)
## 问题描述、样例与输入输出

### 问题描述

给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。


### 问题样例

	示例1:
	输入: 
	给定二叉树: [3,9,20,null,null,15,7],
	
		3
	   / \
	  9  20
	    /  \
	   15   7
	  
	输出: 
	[
	  [3],
	  [9,20],
	  [15,7]
	]
	
### 函数输入与输出

* 输入：
	* TreeNode* root：二叉树的根节点
* 输出：
	* vector<vector<int>>：层次遍历的结果，是一个二维矢量的形式

## 思路	
### 基于队列的层次遍历（BFS）

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
		

 
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题，利用队列做BFS，这里的BFS其实就是一个层次遍历。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
