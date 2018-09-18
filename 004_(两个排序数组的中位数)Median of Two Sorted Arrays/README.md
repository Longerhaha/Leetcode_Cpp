# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 004_(两个排序数组的中位数)Median of Two Sorted Arrays
## 问题描述、输入输出与样例

### 问题描述

给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

你可以假设 nums1 和 nums2 不同时为空。


### 函数输入与输出

* 输入：
	* vector<int>& nums1：输入的有序数组 nums1
	* vector<int>& nums2：输入的有序数组 nums2
* 输出：
	* 
	
### 问题样例

	示例1:
	输入: 
	nums1 = [1, 3]
	nums2 = [2]
	  
	输出: 
	2.0
	
	示例2:
	输入: 
	nums1 = [1, 2]
	nums2 = [3, 4]
	  
	输出: 
	(2 + 3)/2 = 2.5
	
## 思路描述与代码	
### 思路描述（搜索第k个元素）
	
比较 nums1 的第 k/2 个元素与 nums2 的第 k/2 个元素，如果前者小，则可以抛弃前者的前 k/2 个元素，否则抛弃后者的前 k/2 个元素。
如此反复直到找到第 k 个元素。

### 代码

	typedef vector<int>::iterator Iter;
    int getKthElement(Iter nums1_begin, Iter nums1_end, Iter nums2_begin, Iter nums2_end, int k){
        //如果 nums1 的大小大于 nums2 的大小则交换，始终保证 nums2 是最大的
        if((nums1_end - nums1_begin) > (nums2_end - nums2_begin))
            return getKthElement(nums2_begin, nums2_end, nums1_begin, nums1_end, k);
        //如果 nums1 没有元素，则根据 k 输出对应的数据
        else if(nums1_begin >= nums1_end)
            return *(nums2_begin + k - 1);
        //如果只有要找的剩一个元素了，则返回两个数组中头部最小的元素
        else if(k <= 1)
            return min(*nums1_begin, *nums2_begin);
        //获取 nums1 的大小 m
        //获取 nums2 的大小 n
        int m = nums1_end - nums1_begin;
        int n = nums2_end - nums2_begin;
        //cout << m << " " << n << endl;
        //获取当前需要比较的元素的长度
        int mid1 = min(m, k / 2);
        int mid2 = min(n, k / 2);
        //第一个数组对于位置的元素比第一个数组对于位置的元素小，则抛弃第一个数组的mid1个元素
        //否则抛弃第2个数组的mid2个元素
        if(*(nums1_begin + mid1 - 1) < *(nums2_begin + mid2 - 1))
            return getKthElement(nums1_begin + mid1, nums1_end, nums2_begin, nums2_end, k - mid1);
        else 
            return getKthElement(nums1_begin, nums1_end, nums2_begin + mid2, nums2_end, k - mid2);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        return (getKthElement(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (len1 + len2 + 1) / 2) + getKthElement(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (len1 + len2 + 2) / 2)) * 1.0 / 2.0;
        
    }
 
## 拓展与思考：
### 拓展

如果让你搜索 x(x >= 3) 个排序数组的中位数呢？

### 思考
本方法时间复杂度为O(k)(k = m + n)，本题还有[O(min(m, n))的方法](https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn))-solution-with-explanation)
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
