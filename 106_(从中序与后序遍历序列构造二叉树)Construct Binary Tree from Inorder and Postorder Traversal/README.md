# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 106_(从中序与后序遍历序列构造二叉树)Construct Binary Tree from Inorder and Postorder Traversal
## 问题描述、样例与输入输出

### 问题描述

根据一棵树的中序遍历与后序遍历构造二叉树。

__注意__:
你可以假设树中没有重复的元素。


### 问题样例

	示例1:
	输入: 
	中序遍历 inorder = [9,3,15,20,7]
	后序遍历 postorder = [9,15,7,20,3]

	输出: 
	    3
	   / \
	  9  20
		/  \
	   15   7
	
### 函数输入与输出

* 输入：
	* vector<int>& inorder：中序遍历的序列的引用
	* vector<int>& postorder：后序遍历的序列的引用
* 输出：
	* TreeNode*：构造的二叉树的根节点

## 思路	
### 递归

	typedef vector<int>::iterator Iter;
    //递归实现根据中序与后序遍历序列构造二叉树
    TreeNode* buildTree_recurse(Iter inbegin, Iter inend, Iter postbegin, Iter postend){
        //如果中序遍历的开始指针与结束指针一致则返回空
        if(inbegin == inend)
            return nullptr;
        //后序遍历的最后一个节点是根节点
        TreeNode* tmp = new TreeNode(*(postend - 1));
        //寻找后序遍历的最后一个节点在中序遍历结果的位置
        Iter mid = find(inbegin, inend, *(postend - 1));
        //递归左子树
        tmp->left = buildTree_recurse(inbegin, mid, postbegin, postbegin + (mid - inbegin));
        //递归右子树
        tmp->right = buildTree_recurse(mid + 1, inend, postbegin + (mid - inbegin), postend - 1);
        //返回根节点
        return tmp;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree_recurse(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
		

## 拓展与思考：
### 拓展
如果让你从前序遍历和后序遍历构造二叉树呢？构造的二叉树会是唯一的吗？
### 思考
本题与从前序遍历和中序遍历构造二叉树思路一致。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
