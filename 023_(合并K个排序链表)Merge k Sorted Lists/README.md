# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 023_(合并K个排序链表)Merge k Sorted Lists
## 问题描述、输入输出与样例

### 问题描述

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

### 函数输入与输出

* 输入：
	* vector<ListNode*> &lists：排序链表的列表，其每一个元素都是一个链表的头结点指针
* 输出：
	* ListNode*：合并后的排序链表的头节点指针
	
### 问题样例

#### 示例1

输入: 

	[
	  1->4->5,
	  1->3->4,
	  2->6
	]

输出: 1->1->2->3->4->4->5->6
	
## 思路描述与代码	
### 思路描述（二分合并）

int len = lists.size();
//链表 i 和链表 len - i - 1 二分合并，合并后放在前半部分
while( len > 1 ){
	for( int i = 0; i <= len / 2 - 1; i++ ) lists[i] = mergeTwoLists(lists[i], lists[len - i - 1]);
	len = len - len / 2;
}

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
//二分合并
ListNode* mergeKLists(vector<ListNode*> &lists) {
	int len = lists.size();
	while( len > 1 ){
		for( int i = 0; i <= len / 2 - 1; i++ ) lists[i] = mergeTwoLists(lists[i], lists[len - i - 1]);
		len = len - len / 2;
	}
	return len == 0 ? nullptr : lists[0];
}
```
## 思考与拓展
### 思考
不妨设链表的平均长度为 k ，则时间复杂度为O（klogk），若使用逐次合并法，时间复杂度是O（k^2）。
### 拓展
如果给你的是数组呢?


	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
