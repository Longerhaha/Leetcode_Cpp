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
    //对任意 K 个一组进行翻转都适用
    const int GROUP = 2;
    ListNode* ReverseGroup(ListNode* preGroupTail, ListNode* curGroupHead){
        //三指针步进
        ListNode* pre = preGroupTail->next;
        ListNode* cur = pre->next;
        ListNode* next = cur == nullptr ? nullptr : cur->next;
        while( cur != curGroupHead ){
            cur->next = pre;
            pre = cur;
            cur = next;
            next = cur == nullptr ? nullptr : cur->next;
        }
        //记录当前组的尾巴，是下一组待翻转的前一组的尾巴
        ListNode* curGroupTail = preGroupTail->next;
        //前一组的尾巴的下一个指向当前组翻转后的头 pre
        preGroupTail->next = pre;
        //当前组的下一个节点指向下个组未翻转前的头
        curGroupTail->next = cur;
        //返回当前组的尾巴
        return curGroupTail;
    }
    
    ListNode* swapPairs(ListNode* head) {
        //虚假头结点便于链表操作
        ListNode* fakeHead = new ListNode(0);
        fakeHead->next = head;
        ListNode* preGroupTail = fakeHead;
        ListNode* cur = fakeHead->next;
        int cnt = 0;
        while( cur ){
            cur = cur->next;
            cnt++;
            //够一组则进行翻转
            if(cnt % GROUP == 0) preGroupTail = ReverseGroup(preGroupTail, cur);
        }
        head = fakeHead->next;
        delete fakeHead;
        return head;
    }
};