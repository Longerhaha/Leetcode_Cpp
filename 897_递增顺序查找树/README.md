# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 897_递增顺序查找树
## 问题描述、样例与输入输出

### 问题描述

给定一个树，按顺序重新排列树，使树中最左边的结点现在是树的根，并且每个结点没有左子结点，只有一个右子结点。

_提示_：

1. 给定树中的结点数介于 1 和 100 之间。
2. 每个结点都有一个从 0 到 1000 范围内的唯一整数值。

### 问题样例

	示例1：
	输入:
	[5,3,6,2,4,null,8,1,null,null,null,7,9]
	
	       5
	      / \
        3    6
	   / \    \
	  2   4    8
	 /        / \ 
	1        7   9
	输出:
	[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
	1
	 \
	  2
	   \
		3
		 \
		  4
		   \
			5
			 \
			  6
			   \
				7
				 \
				  8
				   \
					9  

	

### 函数输入与输出：
* 输入：
	* TreeNode* root：带重排二叉树的根节点指针
* 输出：
	* TreeNode*：重排后的二叉树根节点指针

## 思路			
### 递归法
	
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
		/*
		 * 这里利用的还是二叉树递归的思想
		 */ 
		TreeNode* increasingBST(TreeNode* root) {
			if(root == nullptr)
				return nullptr;
			/*
			 * 1.把左子树重排，并返回左子树重排的根节点指针
			 * 2.把右子树重排，并返回右子树重排的根节点指针
			 */
			
			TreeNode* left = increasingBST(root->left);
			TreeNode* right = increasingBST(root->right);
			/*
			 * 3.建立根节点，并右子树指向右子树重排的根节点指针
			 */
			TreeNode* mid = new TreeNode(root->val);
			mid->right = right;
			/*
			 * 4.如果左子树重排的根节点指针为空，则直接返回即可
			 *   否则需要找到左子树重回后的尾巴，并指向根节点，并返回左子树重排的根节点指针
			 */
			if(left == nullptr)
				return mid;
			else{
				TreeNode* tmp = left;
				while(tmp->right){
					tmp = tmp->right;
				}
				tmp->right = mid;
				return left;
			}
		}
	};
	
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题与114题[二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/)思路是比较类似的。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
