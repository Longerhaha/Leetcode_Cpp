# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 109_(有序链表转换为二叉搜索树)Convert Sorted List to Binary Search Tree
## 问题描述、样例与输入输出

### 问题描述

给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。


### 问题样例

	示例1:
	输入: 
	给定的有序链表： [-10, -3, 0, 5, 9],
	输出: 
	一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

		  0
		 / \
	   -3   9
	   /   /
	 -10  5
	 
### 函数输入与输出

* 输入：
	* ListNode* head：有序链表的头节点指针
* 输出：
	* TreeNode*：高度平衡二叉搜索树的根节点指针

## 思路	
### 快慢指针分离链表，递归构造

	TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        //只有一个节点的情况
        if(head->next == nullptr){
            return new TreeNode(head->val);
        }
        //分离链表为两个部分
        //快慢指针法，快指针走两部，慢指针走一步
        ListNode*fast, *slow;
        slow = head;
        fast = head->next == nullptr ? nullptr : head->next->next;
        while(fast != nullptr){
            fast = fast->next == nullptr ? nullptr : fast->next->next;
            slow = fast == nullptr ? slow : slow->next;
        }
        //根据slow的下一个节点建立树的跟节点
        TreeNode* root = new TreeNode(slow->next->val);
        //记住分离为两个链表后，下一个链表的表头
        ListNode* list2_head = slow->next->next;
        //第一个链表的最后一个节点的下一个节点指向空
        slow->next = nullptr;
        //根据分离后的两个链表左右递归子树
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(list2_head);
        return root;
    }
		
## 拓展与思考：
### 拓展
如果给定的链表不是有序的呢？甚至是有重复数据的呢？
### 思考
本题，利用快慢指针分离链表，其余和108题将有序数组转换为二叉搜索树的思路一致。
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
