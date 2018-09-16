# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 104_Maximum Depth of Binary Tree(二叉树的最大深度)
## 问题描述、样例与输入输出

### 问题描述

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

__说明__: 叶子节点是指没有子节点的节点。

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
	3
	
### 函数输入与输出

* 输入：
	* TreeNode* root：二叉树的根节点
* 输出：
	* int：最远叶子节点的最长路径上的节点数

## 思路	
### 基于队列的层次遍历（BFS）

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
		

## 拓展与思考：
### 拓展
最远叶子节点的最长路径呢？
### 思考
本题较为简单，直接做个BFS即可。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
