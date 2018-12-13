class Solution {
    typedef vector<int>::iterator iter;
public:
    
    //函数中涉及到的c++知识
    //vector<int> 是个长度可变的int数组，c++里面成为容器
    //ret_func_type func(vector<int>& name) 中的name是vector<int>容器的引用，可以理解为传入一个指针
    //vector<int>::iterator 是c++中的迭代器，可以理解为一个长度可变的int数组的指针类型
    
    
    //快排中的一个partition步骤
    //以val = nums[end]为参考点，分离成 比首元素大的节点 + val + 比首元素小的节点
    //返回 val 最后所在的下标
    int partition(vector<int>& nums, int start, int end){
        int i = start + 1;
        int j = end;
        while( i <= j ){
            while( i <= j && nums[i] > nums[start] ) i++;
            while( i <= j && nums[j] < nums[start] ) j--;
            if(i < j) swap(nums[i++], nums[j--]);
            else break;
        }
        swap(nums[start], nums[j]);
        return j;
    }
    //基于快排partition的查找第K个最大元素的方法
    int qsort_partition_findKthLargest(vector<int>& nums, int start, int end, int k){
        int pos = partition(nums, start, end);
        //如果恰好是第 k - 1 个元素
        if(pos == k - 1) return nums[pos];
        //如果返回的位置比要求的位置大，则说明需要去左边找
        else if(pos > k - 1) return qsort_partition_findKthLargest(nums, start, pos - 1, k);
        //如果返回的位置比要求的位置小，则说明需要去右边找
        else return qsort_partition_findKthLargest(nums, pos + 1, end, k);
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        //基于快排partition的查找第K个最大元素的方法
        return qsort_partition_findKthLargest(nums, 0, nums.size() - 1, k);
    }
    
    
};