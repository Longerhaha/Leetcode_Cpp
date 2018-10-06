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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        else if(l2 == nullptr) return l1;
        else{
            if(l1->val < l2->val){
                l1->next = mergeTwoLists(l1->next, l2);
                return l1;
            } 
            else{
                l2->next = mergeTwoLists(l1, l2->next);
                return l2;
            }
        }
    }
    //二分合并
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        int len = lists.size();
        while( len > 1 ){
            for( int i = 0; i <= len / 2 - 1; i++ ) lists[i] = mergeTwoLists(lists[i], lists[len - i - 1]);
            len = len - len / 2;
        }
        return len == 0 ? nullptr : lists[0];
    }
};