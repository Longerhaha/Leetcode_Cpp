class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0, end = len - 1;
        //二分查找
        while( start < end ){
            int mid = (start + end) / 2;
            if(nums[mid] == target) return mid; 
            else if(nums[mid] < target) start = mid + 1;
            else end = mid;
        }
        //当 target 比 nums[len - 1] 还大时，跳出来时 start = end =  len - 1 且 nums[start] < target
        //当 target 比 nums[len - 1] 小时，跳出来时 start = end 且 nums[start] >= target
        return nums[start] >= target ? start : len;
    }
};