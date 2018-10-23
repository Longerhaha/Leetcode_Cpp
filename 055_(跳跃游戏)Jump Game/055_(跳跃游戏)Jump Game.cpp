class Solution {
public:
    bool canJump(vector<int>& nums) {
        int numsSize = nums.size();
        int max_jump = nums[0];
        for( int i = 0; i < numsSize - 1; i++ ){
            //局部最优
            if(i == max_jump && nums[i] == 0) return false;
            else max_jump = max(max_jump, i + nums[i]);
        }
        return max_jump >= numsSize - 1;
    }
};