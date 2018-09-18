class Solution {
public:
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
        if(*(nums1_begin + mid1 - 1) < *(nums2_begin + mid2 - 1)){
            return getKthElement(nums1_begin + mid1, nums1_end, nums2_begin, nums2_end, k - mid1);
        }
        else 
            return getKthElement(nums1_begin, nums1_end, nums2_begin + mid2, nums2_end, k - mid2);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        return (getKthElement(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (len1 + len2 + 1) / 2) + getKthElement(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), (len1 + len2 + 2) / 2)) * 1.0 / 2.0;
        
    }
    
    
};