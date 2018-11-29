class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        vector<int> dp_pos_max(len, -2147483648);
        vector<int> dp_neg_min(len, 2147483647);
        int maxProd;
        maxProd = dp_pos_max[0] = dp_neg_min[0] = nums[0];
        for( int i = 1; i < len; i++ ){
            dp_pos_max[i] = max(dp_pos_max[i - 1] * nums[i], max(dp_neg_min[i - 1] * nums[i], nums[i]));
            dp_neg_min[i] = min(dp_neg_min[i - 1] * nums[i], min(dp_pos_max[i - 1] * nums[i], nums[i]));
            maxProd = max(maxProd, dp_pos_max[i]);
        }
        return maxProd;
    }
};