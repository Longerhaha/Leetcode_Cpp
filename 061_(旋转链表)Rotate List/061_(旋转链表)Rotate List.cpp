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
    //注意输入的 k 可能远大于链表的长度
    ListNode* rotateRight(ListNode* head, int k) {
        //负面案例
        if(k == 0 || head == nullptr) return head;
        //建立虚假头结点更容易操作
        ListNode* fake_head = new ListNode(0);
        fake_head->next = head;
        //快慢指针间隔 k 步
        ListNode *fast = fake_head, *slow = fake_head;
        int cnt = 0;
        while( fast->next ){
            if(cnt == k) slow = slow->next;
            else cnt++;
            fast = fast->next;
        }
        //如果输入的 k 大于链表的长度
        if(slow == fake_head){
            k = k % cnt;
            return rotateRight(head, k);
        }
        else{
            //旋转
            fake_head->next = slow->next;
            fast->next = head;
            slow->next = nullptr;
        }
        //删除虚假头节点
        head = fake_head->next;
        delete fake_head;
        return head;
    }
};