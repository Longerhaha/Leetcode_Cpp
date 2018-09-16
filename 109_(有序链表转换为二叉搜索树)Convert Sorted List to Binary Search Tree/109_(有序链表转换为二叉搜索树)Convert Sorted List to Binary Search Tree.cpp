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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        //只有一个节点的情况
        if(head->next == nullptr){
            return new TreeNode(head->val);
        }
        //分离链表为两个部分
        //快慢指针法，快指针走两部，慢指针走一步
        ListNode*fast, *slow;
        slow = head;
        fast = head->next == nullptr ? nullptr : head->next->next;
        while(fast != nullptr){
            fast = fast->next == nullptr ? nullptr : fast->next->next;
            slow = fast == nullptr ? slow : slow->next;
        }
        //根据slow的下一个节点建立树的跟节点
        TreeNode* root = new TreeNode(slow->next->val);
        //记住分离为两个链表后，下一个链表的表头
        ListNode* list2_head = slow->next->next;
        //第一个链表的最后一个节点的下一个节点指向空
        slow->next = nullptr;
        //根据分离后的两个链表左右递归子树
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(list2_head);
        return root;
    }
};