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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        ListNode* fast = fake_head;
        ListNode* slow = fake_head;
        int step = 0;
        while( fast->next != nullptr ){
            fast = fast->next;
            step++;
            if(step > n) slow = slow->next;
        }
        slow->next = slow->next->next;
        head = fake_head->next;
        delete fake_head;
        return head;
    }
};