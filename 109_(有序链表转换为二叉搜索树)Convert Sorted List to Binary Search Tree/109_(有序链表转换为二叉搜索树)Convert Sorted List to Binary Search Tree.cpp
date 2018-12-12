/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    //函数中涉及到的指针操作
    //head 为 ListNode* 类型的指针， head->val 是这个指针所指向的节点的值
    //head->next 为 head 所指向的节点的下一个节点的指针
    
    //TreeNode* root = new TreeNode(val) 返回从堆中生成一个值为 val 的链表节点的指针给root
    //root->left 是 root 所指向节点的左子树的指针, root->right 同理
    
    //解题思路
    //1.快慢指针分离成左子树所有节点构成的链表、根节点和右子树所有节点构成的链表
    //2.根据根节点递归分离的两个链表，第一个链表为左子树，第二个链表为右子树 
    TreeNode* sortedListToBST(ListNode* head) {
        //边界情况:链表为空或者只有一个节点
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return new TreeNode(head->val);
        
        //1.快慢指针分离成根节点、左子树所有节点构成的链表和右子树所有节点构成的链表
        //slow为二叉搜索树左子树所有节点构成的链表的链表的尾巴，其链表头为head
        //slow->next->val为二叉搜索树根节点的值
        //slow->next->next为二叉搜索树右子树所有节点构成的链表的头节点指针
        ListNode *slow = head, *fast = head->next;
        while( fast != nullptr ){
            fast = fast->next == nullptr ? nullptr : fast->next->next;
            slow = fast == nullptr ? slow : slow->next;
        }
        //2. 根据根节点递归分离的两个链表，第一个链表为左子树，第二个链表为右子树
        TreeNode* root = new TreeNode(slow->next->val);
        slow->next = nullptr;//分离第一个链表
        ListNode* list2head = slow->next->next;//获取第二个链表的头节点指针
        //递归构造二叉搜索树
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(list2head);
        return root;
    }
};