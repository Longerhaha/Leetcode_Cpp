# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 002_(两数相加)Add Two Numbers
## 问题描述、输入输出与样例

### 问题描述

给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

### 函数输入与输出

* 输入：
	* ListNode* l1：非空链表1
	* ListNode* l2：非空链表2
* 输出：
	* ListNode*：相加后的链表的头结点指针
	
### 问题样例

#### 示例1

	输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
	输出：7 -> 0 -> 8
	原因：342 + 465 = 807
	
	
## 思路描述与代码	
### 思路描述（常规法）
temp 代表进位，然后一直往后加，知道某一链表为空了，此时再把剩余的链表与进位加起来。

### 代码

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
 
## 拓展与思考：
### 拓展
如果给你的数据是数组数据呢？顺便思考下为啥这个题目给你的数是反序呢？
### 思考
本题是常规的链表操作。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
