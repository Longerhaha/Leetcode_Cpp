# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 019_(删除链表的倒数第N个节点)Remove Nth Node From End of List
## 问题描述、输入输出与样例

### 问题描述

给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

_说明_：

给定的 n 保证是有效的。

__进阶__：

你能尝试使用一趟扫描实现吗？

### 函数输入与输出

* 输入：
	* ListNode* head：链表的头结点指针
	* int n：删除链表的倒数第 n 个节点
* 输出：
	* ListNode*：删除链表的倒数第 n 个节点后的链表的头结点指针
	
### 问题样例

#### 示例1

输入: 给定一个链表1->2->3->4->5, 和 n = 2.

输出: 1->2->3->5

## 思路描述与代码	
### 思路描述（间隔 n 的双指针法）
构造步长差为 n 的快指针 fast 和慢指针 slow ，当快指针指向链表的最后一个节点时，慢指针指向倒数的第 n + 1 个节点，然后慢指针跳过下一个指针指向其下下个指针即可。

整个过程只需要一次扫描。

### 代码
```cpp
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
```
## 思考与拓展
### 思考
建立空头结点往往能使操作更加简便，使用快慢指针法是链表中常见的操作。
### 拓展
如果给你的是双向链表呢？多加几步操作而已。
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
