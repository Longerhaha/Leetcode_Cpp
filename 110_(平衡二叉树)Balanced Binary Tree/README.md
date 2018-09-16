# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 110_(平衡二叉树)Balanced Binary Tree
## 问题描述、样例与输入输出

### 问题描述

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。


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
	true
	
	示例2:
	输入: 
	给定二叉树: [1,2,2,3,3,null,null,4,4],
		   1
		  / \
		 2   2
		/ \
	   3   3
	  / \
	 4   4
	  
	输出: 
	false
	
	
### 函数输入与输出

* 输入：
	* TreeNode* root：二叉树的根节点
* 输出：
	* bool：是否是一棵平衡的二叉树

## 思路	
### 递归

	int depth_dfs(TreeNode* root){
        //如果输入为空指针，返回深度0
        if(root == nullptr)
            return 0;
        //求左子树的长度与右子树的长度
        int left_depth = depth_dfs(root->left);
        int right_depth = depth_dfs(root->right);
        //如果左子树不平衡、右子树不平衡或者他自己不平衡，返回-1
        if(left_depth == -1 || right_depth == -1 || abs(left_depth - right_depth) > 1)
            return -1;
        //否则获取该根节点的深度
        else
            return max(left_depth, right_depth) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return (depth_dfs(root) != -1);
    }

 
## 拓展与思考：
### 拓展
如果让你判断是否是一棵二叉平衡搜索树呢？
### 思考
本题，遍历求深度，并在求深度的同时判断是否是一棵二叉平衡树。
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
