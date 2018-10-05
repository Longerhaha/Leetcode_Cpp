class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int closet = nums[0] + nums[1] + nums[2];
        for( int i = 0; i < len; i++ ){
            int start = i + 1;
            int end = len - 1;
            while( start < end ){
                int three_sum = nums[i] + nums[start] + nums[end];
                closet = abs(target - closet) < abs(target - three_sum) ? closet : three_sum;
                if(target - three_sum == 0) return closet;
                else if(target - three_sum > 0) start++;
                else end--;
            }
        }
        return closet;
    }
};