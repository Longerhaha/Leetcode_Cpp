class Solution {
public:
    //哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> map;
        for( int i = 0; i < nums.size(); i++ ){
            //如果另外一个之前出现过，则找到了
            if(map.count(target - nums[i]) > 0){
                ans.push_back(map[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            //否则记录在哈希表内
            else{
                map[nums[i]] = i;
            }
        }
        
        //都没有找到
        return ans;
    }
};