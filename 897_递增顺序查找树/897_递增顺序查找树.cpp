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