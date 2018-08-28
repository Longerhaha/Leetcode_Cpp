# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 894_所有可能的完整二叉树
## 问题描述与输入输出
完整二叉树是一类二叉树，其中每个结点恰好有 0 或 2 个子结点。

返回包含 N 个结点的所有可能完整二叉树的列表。 答案的每个元素都是一个可能树的根结点。

答案中每个树的每个结点都必须有 node.val=0。

你可以按任何顺序返回树的最终列表。

### 问题样例

	示例1：
	输入:
	7
	输出:
	[[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]
	解释：
	树的图片可以在[此网页](https://leetcode-cn.com/contest/weekly-contest-99/problems/all-possible-full-binary-trees/)看到。
	

函数输入与输出：
* 输入：
	* int N：树的节点数目
* 输出：
	* vector<TreeNode*>：N 个结点的所有可能完整二叉树的列表

## 思路			
### 递归法
	
	vector<TreeNode*> allPossibleFBT(int N) {
	    //递归结束条件
        if(N == 1){
            return {new TreeNode(0)};
        }
        vector<TreeNode*> ans;
        for( int i = 1; i < N; i += 2 ){
			//左子树有i个节点，可能性有left.size()种，根节点一个，右子树有N - 1 - i个节点，可能性有right.size()种
            vector<TreeNode*> left = allPossibleFBT(i), right = allPossibleFBT(N - 1 - i);
            for( int j = 0; j < left.size(); j++ ){
                for( int k = 0; k < right.size(); k++){
                    TreeNode* root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
	
## 拓展与思考：
### 拓展
暂无
### 思考
本题重在排序，从而使同一组元素的字符串even+odd一致，再利用哈希表的无重复性直接返回哈希表中已有的元素的数目即可。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
