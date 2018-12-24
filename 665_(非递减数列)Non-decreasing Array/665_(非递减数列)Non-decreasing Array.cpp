class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                cnt++;
                //cnt = 1时，需要注意有两种情况可以补救：
                //1. 比如[-1 4 2 3], 4 < 2, 2 > -1, 通过修改 4  为 -1~2 间的数都可以补救
                //2. 比如[1 2 -1 3],-1 < 2, 2 < 3,  通过修改 -1 为  2~3 间的数都可以补救

                //cnt >= 2则怎样都不行了，因为只能修改一次
                if((cnt == 1 && i >= 2 && i < n - 1 && nums[i] < nums[i - 2] && nums[i + 1] < nums[i - 1]) || cnt >= 2) return false;
            }
        }
        return true;
    }
};