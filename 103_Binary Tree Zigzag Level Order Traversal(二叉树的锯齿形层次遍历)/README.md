# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 103_Binary Tree Zigzag Level Order Traversal(二叉树的锯齿形层次遍历)
## 问题描述、样例与输入输出

### 问题描述

给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

### 问题样例

	示例1:
	输入: 
	给定二叉树:[3,9,20,null,null,15,7]
	
		3
	   / \
	  9  20
	    /  \
	   15   7
	  
	输出: 
	[
	  [3],
	  [20,9],
	  [15,7]
	]
	
### 函数输入与输出

* 输入：
	* TreeNode* root：二叉树的根节点
* 输出：
	* vector<vector<int>>：锯齿形层次遍历，是一个二维矢量的形式

## 思路	
### 基于队列的层次遍历（BFS）

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
		

 
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题，可以使用双端队列或者结合队列与列表实现类似双端队列的功能，直接从102题改过来做个变形即可。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
