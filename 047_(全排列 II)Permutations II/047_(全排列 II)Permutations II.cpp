class Solution {
public:
    void permuteUnique_BacktTrack(vector<vector<int>> &ans, vector<int>& nums, int start){
        if(start == nums.size()) ans.push_back(nums);
        for( int i = start; i < nums.size(); i++ ){
            //去重
            //如果 nums[i] 与 nums[start, start + 1, ... i-2, i-1]都不重复则可以继续下一个排列
            int j = i - 1;
            while(j >= start && nums[j] != nums[i]) j--;
            if(i == start || j == start - 1){
                swap(nums[i], nums[start]);
                permuteUnique_BacktTrack(ans, nums, start + 1);
                swap(nums[i], nums[start]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        sort(nums.begin(), nums.end());
        permuteUnique_BacktTrack(ans, nums, 0);
        return ans;
    }
};