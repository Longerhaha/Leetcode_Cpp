class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0) return -1;
        int start = 0, end = len - 1;
        while(start < end){
            int mid = (start + end) / 2;
            if(nums[mid] == target) return mid;
            //左边有序、右边乱序
            else if(nums[start] <= nums[mid]){
                if(nums[start] <= target && target < nums[mid]) end = mid - 1;
                else start = mid + 1;
            }
            //右边有序、左边乱序
            else{
                if(nums[mid] < target && target <= nums[end]) start = mid + 1;
                else end = mid - 1;
            }
        }
        return nums[start] == target ? start : -1;
    }
};