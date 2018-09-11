# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 105_Construct Binary Tree from Preorder and Inorder Traversal(从前序与后序遍历序列构造二叉树)
## 问题描述、样例与输入输出

### 问题描述

根据一棵树的前序遍历与中序遍历构造二叉树。

__注意__:
你可以假设树中没有重复的元素。


### 问题样例

	示例1:
	输入: 
	前序遍历 preorder = [3,9,20,15,7]
	中序遍历 inorder = [9,3,15,20,7]

	输出: 
	    3
	   / \
	  9  20
		/  \
	   15   7
	
### 函数输入与输出

* 输入：
	* vector<int>& preorder：前序遍历的序列的引用
	* vector<int>& inorder：中序遍历的序列的引用
* 输出：
	* TreeNode*：构造的二叉树的根节点

## 思路	
### 基于队列的层次遍历（BFS）

	typedef vector<int>::iterator Iter;
    //基于递归形式的前序与中序遍历序列构造二叉树
    TreeNode* buildTree_recurse(Iter preoroder_begin, Iter preoroder_end, Iter inorder_begin, Iter inorder_end){
        //如果只有一个节点
        if(preoroder_begin == preoroder_end - 1){
            return (new TreeNode(*preoroder_begin));
        }
        //先建立根节点
        TreeNode* root = new TreeNode(*preoroder_begin);
        //根据先序遍历结果找到其在中序遍历结果中的指针位置
        Iter div = find(inorder_begin, inorder_end, *preoroder_begin);
        //如果没有左子树
        if(div == inorder_begin)
            root->left = nullptr;
        //否则递归左子树
        else
            root->left = buildTree_recurse(preoroder_begin + 1, preoroder_begin + 1 + (div - inorder_begin), inorder_begin, div);
        //如果没有右子树
        if(div == inorder_end - 1)
            root->right = nullptr;
        //否则递归右子树
        else
            root->right = buildTree_recurse(preoroder_begin + (div - inorder_begin) + 1, preoroder_end, inorder_begin + (div - inorder_begin) + 1, inorder_end);
        //返回根节点
        return root;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        //如果输入为空，则返回空
        if(preorder.size() == 0)
            return nullptr;
        else
            return buildTree_recurse(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
		

## 拓展与思考：
### 拓展
如果让你从中序遍历和后序遍历构造二叉树呢？
### 思考
本题较为简单，利用递归的思想即可。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
