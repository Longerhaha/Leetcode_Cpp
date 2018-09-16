# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 138_(复制带随机指针的链表)Copy List with Random Pointer
## 问题描述、样例与输入输出

### 问题描述

给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。

要求返回这个链表的深度拷贝。 

### 问题样例

	无示例。

### 函数输入与输出

* 输入：
	* RandomListNode *head：带随机节点的链表的头结点指针。
* 输出：
	* RandomListNode *head：深度拷贝带随机节点的链表的头结点指针。

## 思路			
### BFS
	
	/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
		/*
		 * 基于队列实现BFS
		 */
        queue<RandomListNode *> q;
		/*
		 * 利用哈希表记录节点与复制节点的映射关系
		 */
        unordered_map<RandomListNode *, RandomListNode *> ump;
		
		//1.处理头结点
        q.push(head);
        RandomListNode *p_copy_head = new RandomListNode(head->label);
        ump[head] = p_copy_head;
		
        while( !q.empty() ){
            RandomListNode *p_tmp = q.front();
            q.pop();
            RandomListNode *p_copy_tmp = ump[p_tmp];
			//如果next指针不为空，则需要根据其下一个节点是否在之前有建立过做出决策
            if(p_tmp->next != NULL){
				//有建立过，则记录下来
                if(ump.count(p_tmp->next) > 0){
                    p_copy_tmp->next = ump[p_tmp->next];
                }
				//未建立过，则建立新节点、建立新节点与当前节点的映射关系并入队列
                else{
                    RandomListNode *p_copy_next = new RandomListNode(p_tmp->next->label);
                    p_copy_tmp->next = p_copy_next;
                    ump[p_tmp->next] = p_copy_next;
                    q.push(p_tmp->next);
                }  
            }
			//同理next
            if(p_tmp->random != NULL){
                if(ump.count(p_tmp->random) > 0){
                    p_copy_tmp->random = ump[p_tmp->random];
                }
                else{
                    RandomListNode *p_copy_random = new RandomListNode(p_tmp->random->label);
                    p_copy_tmp->random = p_copy_random;
                    ump[p_tmp->random] = p_copy_random;
                    q.push(p_tmp->random);
                }  
            } 
        }
        return p_copy_head;
    }
};
	
	
## 拓展与思考：
### 拓展
暂无。
### 思考
在133_Clone Graph(克隆图)写过DFS的代码。本题与之类似，DFS与BFS都可以用，之前写过DFS，于是今天写利用队列实现BFS的代码。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
