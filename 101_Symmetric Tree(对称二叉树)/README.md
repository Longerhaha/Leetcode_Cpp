# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 101_Symmetric Tree(对称二叉树)
## 问题描述、样例与输入输出

### 问题描述

给定一个二叉树，检查它是否是镜像对称的。


### 问题样例

	示例1:
	输入: 
	给定二叉树: [1,2,2,3,4,4,3] ,
	
	    1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
	  
	输出: 
	true
	
	示例2:
	输入: 
	给定二叉树: [1,2,2,null,3,null,3] ,
	
	    1
	   / \
	  2   2
	   \   \
	   3    3
	  
	输出: 
	false
	
### 函数输入与输出

* 输入：
	* TreeNode* root：二叉树的根节点
* 输出：
	* bool：是否是对称二叉树

## 思路	
### 队列遍历

	//递归较为简单，这里使用迭代的方式解决这个问题
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        //使用队列做遍历，这是也可以使用堆栈
        queue<TreeNode*> q;
        //根节点就不用判断了，直接加入左右孩子节点
        q.push(root->left);
        q.push(root->right);
        while( !q.empty() ){
            //从队列弹出两个节点
            TreeNode* tmp1 = q.front();
            q.pop();
            TreeNode* tmp2 = q.front();
            q.pop();
            //如果都是根节点，则结束本次循环
            if(tmp1 == nullptr && tmp2 == nullptr)
                continue;
            //如果不对称，则返回false
            if((tmp1 == nullptr && tmp2) || (tmp2 == nullptr && tmp1) || (tmp1->val != tmp2->val))
                return false;
            //对称入队
            q.push(tmp1->left);
            q.push(tmp2->right);
            q.push(tmp1->right);
            q.push(tmp2->left);
        }
        //都是对称的，返回真
        return true;
    }
		

 
## 拓展与思考：
### 拓展
如果让你判断是不是同构的呢？
### 思考
本题，利用队列和堆栈做迭代都可以解决这个问题。	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
