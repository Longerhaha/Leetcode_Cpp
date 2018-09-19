# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 889_(根据前序和后序遍历构造二叉树)Construct Binary Tree from Preorder and Postorder Traversal
## 问题描述、输入输出与样例

### 问题描述
返回与给定的前序和后序遍历匹配的任何二叉树。

 pre 和 post 遍历中的值是不同的正整数。


### 函数输入与输出

* 输入：
	* vector<int>& pre：前序遍历的一维矢量
	* vector<int>& post：后序遍历的一维矢量
* 输出：
	* TreeNode*：根据前序和后序遍历构造的二叉树的根节点指针。
	
### 问题样例

	示例1:
	输入: 
	pre = [1,2,4,5,3,6,7]
	post = [4,5,2,6,7,3,1]
	  
	输出: 
	[1,2,3,4,5,6,7]
	
	提示：
	* 1 <= pre.length == post.length <= 30
	* pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列
	* 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。
	
	
## 思路描述与代码	
### 思路描述（递归）

递归构造树

由于从前序和后序构造的二叉树不是唯一的，这里需要设置自定义的规则，才方便递归构造二叉树

规则如下：

以 pre[0] 为根节点 root ，根据 pre[1] 在 post 的位置拆分为两部分，然后递归root左子树为左部分，递归root右子树为右部分

比如：
pre = [1,2,4,5,3,6,7]

post = [4,5,2,6,7,3,1]

以 pre[0] 为1构造根节点， 2在 post 中的下标为2，可以以此划分剩余的 pre 和 post

pre划分如下[2,4,5],[3,6,7];post划分如下[4,5,2],[7,3,1];然后递归左右子树为左半部分构造的树、右半部分构造的树即可。

### 代码

	typedef vector<int>::iterator Iter;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        
        return constructFromPrePost_recurse(pre.begin(), pre.end(), post.begin(), post.end());
    }
    
    TreeNode* constructFromPrePost_recurse(Iter pre_begin, Iter pre_end, Iter post_begin, Iter post_end){
        if(pre_begin >= pre_end)
            return nullptr;
        else if(pre_end - pre_begin <= 1)
            return (new TreeNode(*pre_begin));
        //以 pre[0] 为根节点构造树
        TreeNode* root = new TreeNode(*pre_begin);
        //找出 pre[1] 在 post 中的位置
        Iter next = find(post_begin, post_end - 1, *(pre_begin + 1));
        //算出长度
        int left_len = next - post_begin + 1;
        //左右递归 root 的左右子树
        root->left = constructFromPrePost_recurse(pre_begin + 1, pre_begin + left_len + 1, post_begin, post_begin + left_len);
        root->right = constructFromPrePost_recurse(pre_begin + 1 + left_len, pre_end, post_begin + left_len, post_end - 1);
        return root;
    }
 
## 拓展与思考：
### 拓展
从前序和中序构造二叉树、从后序和中序构造二叉树相对较为简单。
### 思考
本题利用的还是递归的思想，对于这种不确定的二叉树，需要自己制定一个规则才能构造出来二叉树。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
