class Solution {
public:
    //回溯方法做
    //解空间树是排列树
    void permute_backtrack(vector<vector<int>> &ans, vector<int>& nums, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
            return ;
        }
        
        for( int i = idx ; i < nums.size(); i++ ){
            swap(nums[idx], nums[i]);
            permute_backtrack(ans, nums, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute_backtrack(ans, nums, 0);
        return ans;
    }
};