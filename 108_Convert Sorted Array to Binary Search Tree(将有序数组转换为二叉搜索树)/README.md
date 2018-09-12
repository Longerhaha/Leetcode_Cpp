# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 108_Convert Sorted Array to Binary Search Tree(将有序数组转换为二叉搜索树)
## 问题描述、样例与输入输出

### 问题描述

将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。


### 问题样例

	示例1:
	输入: 
	给定二叉树: [-10,-3,0,5,9]
	输出: 
	一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

		  0
		 / \
	   -3   9
	   /   /
	 -10  5
### 函数输入与输出

* 输入：
	* vector<int>& nums：有序数组的引用
* 输出：
	* TreeNode*：高度平衡二叉搜索树的根节点指针

## 思路	
### 递归

	typedef vector<int>::iterator Iter; 
    TreeNode* sortedArrayToBST_recurse(Iter begin, Iter end){
        //如果输入的指针一致，则返回空
        if(begin == end)
            return nullptr;
        //找到中间节点
        Iter mid = begin + (end - begin) / 2;
        //生成以中间节点为根节点的树
        TreeNode* root = new TreeNode(*mid);
        //递归左子树
        root->left = sortedArrayToBST_recurse(begin, mid);
        //递归右子树
        root->right = sortedArrayToBST_recurse(mid + 1, end);
        //返回根节点
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST_recurse(nums.begin(), nums.end());
    }
		
## 拓展与思考：
### 拓展
如果给你的数据是个链表呢？
### 思考
本题，由于给定了数的规模，而且数据是有序的，所以本题还是好做的。
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
