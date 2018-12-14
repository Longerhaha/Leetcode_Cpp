# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 347_(前K个高频元素)Top K Frequent Element
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。<br>
__说明__：
* 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
* 你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
### 1.2 输入与输出
输入：
* vector<int>& nums:给定非空整数数组
* int k:频率前 k 高

输出：
* vector<int>:频率前 k 高的元素
### 1.3 样例
#### 1.3.1 样例1
输入: nums = [1,1,1,2,2,3], k = 2<br>
输出: [1,2]
#### 1.3.2 样例2
输入: nums = [1], k = 1<br>
输出: [1]
## 2 思路描述与代码	
### 2.1 思路描述（哈希表+桶排序）
1. 先把数组所有元素插入哈希表
2. 遍历哈希表, 插入桶中, 桶的下标是哈希表的关键字的个数, 桶的值是哈希表的关键字
3. 从桶末尾开始遍历桶直到取得桶的高k位数据

比如输入[1,1,1,2,2,3]
遍历插入哈希表map后，map = {1:3,2:4,3:1}（顺序是乱的）, 其中1：3代表1出现了3次<br>
然后遍历哈希表，插入桶中，有桶bucket = [[3], [null], [1], [2]]<br>
从桶末尾开始遍历直至取出两个元素，于是结果是[1, 2]<br>
### 2.2 代码
```cpp
//函数中涉及到的c++知识
//vector<int> 是个长度可变的int数组，c++里面称为容器
//vector<vector<int>> 是个长度可变且长度不一的二维int数组，每行又是一个长度可变的int数组
//ret_func_type func(vector<int>& name) 中的name是vector<int>容器的引用，可以理解为传入一个指针
//unordered_map<int, int> map是一个无序哈希表，哈希的键值key是唯一的
//map[val]就是获得val在哈希表map中的个数

//时间复杂度O(n) 哈希表+桶排序
vector<int> topKFrequent(vector<int>& nums, int k) {
    //1. 先把数组所有元素插入哈希表
    unordered_map<int, int> map;
    for( int i = 0; i < nums.size(); i++ ) map[nums[i]]++;
    //2. 遍历哈希表，插入桶中
    //桶的下标是哈希表关键字的个数, 桶的值是哈希表的关键字
    vector<vector<int>> bucket(nums.size());
    //it->second是关键字的个数，it->first是哈希表的关键字
    for (auto it = map.begin(); it != map.end(); ++it) bucket[it->second - 1].push_back(it->first);
    
    //3. 从桶末尾开始遍历桶直到取得桶的高k位数据
    vector<int> ans;
    int ans_num = 0;
    for( int i = nums.size() - 1; i >= 0; i-- ){
        if(bucket[i].size() != 0){
            for( int j = 0; j < bucket[i].size(); j++ ){
                ans.push_back(bucket[i][j]);
                if(++ans_num == k) return ans;
            }
        }
    }
    //出错
    return {-1};
}
```
## 3 思考与拓展
### 3.1 思考
本题使用桶排序使得时间复杂度降低为O(n)，此外在插入哈希表后你也可以使用优先队列或者最大堆这种的结构来求前k个高频元素。
#### 3.1.1 其他方法
#### 3.1.1.1 哈希表+优先队列
1. 先把数组所有元素插入哈希表
2. 队列节点的结构是{哈希表的关键字的个数，哈希表的关键字}，遍历哈希表, 插入优先队列（以哈希表的关键字的个数从大到小排列）中。
3. 从优先队列头中取出前k个节点

#### 3.1.1.2 哈希表+最大堆
1. 先把数组所有元素插入哈希表
2. 堆节点的结构是{哈希表的关键字的个数，哈希表的关键字}，遍历哈希表, 插入堆中（以哈希表的关键字的个数从大到小以树形结构排列）中。
3. 从优先队列头中取出前k个节点

#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
哈希表+桶排序|O(n)|O(n)
哈希表+优先队列|O(n)|O(nlogn)
哈希表+最大堆|O(n)|O(nlogn)
#### 3.1.3 难点分析
1. 在插入哈希表后，需要选择以关键字还是关键字的个数来作为排序的依据

### 3.2 拓展
如果给你的是链表数据会影响他的时间与空间复杂度吗？

	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
