/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *h = new ListNode(0);
        ListNode *p = h;
        int temp = 0;
        while(l1 != NULL && l2 != NULL) {
            p->next = new ListNode((temp + l1->val + l2->val) % 10);
            temp = (temp + l1->val + l2->val) / 10;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            p->next = new ListNode((temp + l1->val) % 10);
            temp = (temp + l1->val) / 10;
            p = p->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            p->next = new ListNode((temp + l2->val) % 10);
            temp = (temp + l2->val) / 10;
            p = p->next;
            l2 = l2->next;
        }
        if(temp) {
            p->next = new ListNode(1);
        }
        return h->next;
    }
};