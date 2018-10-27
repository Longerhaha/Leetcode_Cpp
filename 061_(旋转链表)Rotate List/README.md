# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 061_(旋转链表)Rotate List
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。
### 1.2 输入与输出
输入：
* ListNode* head:链表的头节点指针
* int k:将链表每个节点向右移动 k 个位置

输出：
* ListNode*:旋转后的链表的头节点指针
### 1.3 样例
#### 1.3.1 样例1
输入: 1->2->3->4->5->NULL, k = 2<br>
输出: 4->5->1->2->3->NULL<br>
解释:<br>
向右旋转 1 步: 5->1->2->3->4->NULL<br>
向右旋转 2 步: 4->5->1->2->3->NULL<br>
#### 1.3.2 样例2
输入: 0->1->2->NULL, k = 4<br>
输出: 2->0->1->NULL<br>
解释:<br>
向右旋转 1 步: 2->0->1->NULL<br>
向右旋转 2 步: 1->2->0->NULL<br>
向右旋转 3 步: 0->1->2->NULL<br>
向右旋转 4 步: 2->0->1->NULL<br>
## 2 思路描述与代码	
### 2.1 思路描述（快慢指针方法）
建立虚假头空节点 fake_head 方便链表的操作。<br>
利用快慢指针方法构造出一个相距 k 个节点的 fast、 slow节点指针。<br>
然后再进行旋转操作：
1. fake_head->next = slow->next;
2. fast->next = head;
3. slow->next = nullptr;

比如输入: 1->2->3->4->5->NULL, k = 2<br>
建立头空节点后链表为： fake_head_node->1->2->3->4->5->NULL<br>
快慢指针的快指针遍历到最后一个节点时有：fake_head_node-> 1 -> 2 -> 3 -> 4 -> 5 -> NULL<br>
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　slow　　　fast<br>
进行旋转操作后有:fake_head_node-> 4 -> 5 -> 1 -> 2 -> 3 -> NULL<br>
然后返回 fake_head_node->next即可。<br>                                                            
值得**注意**的是由于题目中 k 是非负数，这也就意味 k 可能等于0 也可能远大于链表的长度，这都是代码中需要处理的问题。
### 2.2 代码
```cpp
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
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
当然你可以先求出链表的长度 len，然后对 k 求模，再利用快慢指针法去旋转，但是这个方法的缺点是当输入的长度小于 len 时你的求 len 操作其实是不必要的。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
快慢指针|O(1)|O(n)
#### 3.1.3 难点分析
1. 快慢指针的出发点应该是 fake_head_node，便于旋转；
2. 输入 k 大于指针长度时的处理。
### 3.2 拓展
如果让你旋转数组呢？这个稍微简单点。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
