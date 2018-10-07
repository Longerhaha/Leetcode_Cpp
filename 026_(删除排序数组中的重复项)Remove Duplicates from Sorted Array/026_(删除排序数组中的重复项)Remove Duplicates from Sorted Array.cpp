class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        int notDupNum = len > 0 ? 1 : 0;
        for( int i = 1; i < len; i++ ){
            if(nums[i] != nums[i - 1]) nums[notDupNum++] = nums[i];
        }
        return notDupNum;
    }
};