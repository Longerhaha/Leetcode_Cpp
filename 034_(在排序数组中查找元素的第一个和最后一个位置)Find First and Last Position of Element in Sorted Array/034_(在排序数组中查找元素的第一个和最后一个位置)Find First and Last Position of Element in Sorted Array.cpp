class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int len = nums.size();
        //输入为空时，返回-1、-1
        if(len == 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        //二分查找
        int start = 0, end = len - 1;
        while( start < end ){
            int mid = (start + end) / 2;
            if(nums[mid] == target){
                //左右扩张与target相等的范围
                int left = mid;
                int right = mid;
                while( left - 1 >= start && target == nums[left - 1] ) left--;
                while( right + 1 <= end && target == nums[right + 1] ) right++;
                ans.push_back(left);
                ans.push_back(right);
                return ans;
            }
            else if(nums[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        if(nums[start] == target){
            ans.push_back(start);
            ans.push_back(end);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};