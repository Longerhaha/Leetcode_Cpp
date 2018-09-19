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
    /* 递归构造树
       由于从前序和后序构造的二叉树不是唯一的，这里需要设置自定义的规则，才方便递归构造二叉树
       规则如下：
       以 pre[0] 为根节点 root ，根据 pre[1] 在 post 的位置拆分为两部分，然后递归root左子树为左部分，递归root右子树为右部分
       
       比如：
       pre = [1,2,4,5,3,6,7]
       post = [4,5,2,6,7,3,1]
       以 pre[0] 为1构造根节点， 2在 post 中的下标为2，可以以此划分剩余的 pre 和 post
       pre划分如下[2,4,5],[3,6,7];post划分如下[4,5,2],[7,3,1];然后递归左右子树为左半部分构造的树、右半部分构造的树即可。
    */
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
};