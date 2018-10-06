# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 021_(合并两个有序链表)Merge Two Sorted Lists
## 问题描述、输入输出与样例

### 问题描述

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

### 函数输入与输出

* 输入：
	* ListNode* l1：有序链表 l2 的头结点指针
	* ListNode* l2：有序链表 l2 的头结点指针
* 输出：
	* ListNode*：合并后的链表的头结点指针
	
### 问题样例

#### 示例1

输入：1->2->4, 1->3->4

输出：1->1->2->3->4->4
	
## 思路描述与代码	
### 思路描述（递归法）

若 l1 为空，则返回 l2；

否则若 l1 为空，则返回 l1；

否则:
	* 若 l1->val < l2->val，则 l1->next = 递归(l1->next, l2) 并返回 l1;
	* 否则 l2->next = 递归(l1, l2->next) 并返回 l2。


### 代码
```cpp
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
```
## 思考与拓展
### 思考
本题也可以改成非递归的实现方式，也较为简单。
### 拓展
如果让你合并 K（K > 2） 个链表呢？
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
