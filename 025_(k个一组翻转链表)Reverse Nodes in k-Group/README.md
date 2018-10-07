# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 025_(k个一组翻转链表)Reverse Nodes in k-Group
## 问题描述、输入输出与样例

### 问题描述

给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

__说明__:

1. 你的算法只能使用常数的额外空间。
2. 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

### 函数输入与输出

* 输入：
	* ListNode* head：输入链表的头结点指针
	* int k：k个节点一组进行反转
* 输出：
	* ListNode*：k个节点一组进行反转后的链表的头结点指针
	
### 问题样例

#### 示例1

输入: 1->2->3->4->5，k = 2

输出: 2->1->4->3->5

#### 示例2

输入: 1->2->3->4->5，k = 3

输出: 3->2->1->4->5

## 思路描述与代码	
### 思路描述（三指针法）

	对链表数据计数，k个反转一次，反转规则如下：

	1. 说明：
	K个一组反转链表
	K个一组也适用2个一组
	preGroupTail 记录上一个已反转链表的尾巴
	nextGroupHead 记录下一组待反转链表的头（可能反转也可能不反转）
	curGroupTail 指向该反转链表反转后的尾巴
	pre 指向反转链表的第一个节点
	cur 指向反转链表的第二个节点
	next 指向反转链表的第三个节点

	2. 规则：
	while( cur != nextGroupHead )
		当 cur 不是下一个反转链表的头，则反转 cur 指向 pre，即cur->next = pre，然后三个指针右移一个节点
	接着做最后的处理：
	//记录当前组的尾巴，是下一组待翻转的前一组的尾巴
	ListNode* curGroupTail = preGroupTail->next;
	//前一组的尾巴的下一个指向当前组翻转后的头 pre
	preGroupTail->next = pre;
	//当前组的下一个节点指向下个组未翻转前的头
	curGroupTail->next = cur;
	//返回当前组翻转后的尾巴
	return curGroupTail;

	


### 代码
```cpp
ListNode* ReverseGroup(ListNode* preGroupTail, ListNode* nextGroupHead){
	//三指针步进
	ListNode* pre = preGroupTail->next;
	ListNode* cur = pre->next;
	ListNode* next = cur == nullptr ? nullptr : cur->next;
	while( cur != nextGroupHead ){
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

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
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
		if(cnt % k == 0) preGroupTail = ReverseGroup(preGroupTail, cur);
	}
	head = fakeHead->next;
	delete fakeHead;
	return head;
}
```
## 思考与拓展
### 思考
本题从两两交换链表中的节点稍微更改即可。
### 拓展
如果给你的是双链表呢？


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
