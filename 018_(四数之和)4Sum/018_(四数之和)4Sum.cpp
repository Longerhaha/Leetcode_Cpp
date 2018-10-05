class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for( int i = 0; i < len; i++ ){
            //四数和去重
            if(i - 1 >= 0 && nums[i] == nums[i - 1])
                continue;
            int threeSum = target - nums[i];
            for( int j = i + 1; j < len; j++ ){
                //三数和去重
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                else{
                    int two_sum = threeSum - nums[j];
                    int start = j + 1;
                    int end = len - 1;
                    while( start < end ){
                        if(nums[start] + nums[end] == two_sum){
                            ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                            //二数和去重
                            while(start < end && nums[start] == nums[start + 1]) start++;
                            while(start < end && nums[end] == nums[end - 1]) end--;
                            start++, end--;
                        }
                        else if(nums[start] + nums[end] < two_sum) start++;
                        else end--;
                    }
                }
            }
        }
        
        return ans;
    }
};