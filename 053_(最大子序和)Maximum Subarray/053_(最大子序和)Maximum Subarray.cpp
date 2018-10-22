class Solution {
public:
    const int MIN = -2147483648;
    int maxSubArray(vector<int>& nums) {
        return maxSubArray_divideAndConquer(nums, 0, nums.size() - 1);
        //return maxSubArray_online_processing(nums);
    }
    //在线处理
    int maxSubArray_online_processing(const vector<int>& nums){
        int len_nums = nums.size();
        int max_sum = MIN;
        int this_sum = 0;
        for( int i = 0; i < len_nums; i++ ){
            this_sum += nums[i];
            max_sum = max(max_sum, this_sum);
            if(this_sum < 0) this_sum = 0;
        }
        return max_sum;
    }
    //分治
    int maxSubArray_divideAndConquer(const vector<int>& nums, const int start, const int end){
        if(start == end) return nums[start];
        int mid = (start + end) / 2;
        //获取左、右部分最大值
        int left_max = maxSubArray_divideAndConquer(nums, start, mid);
        int right_max = maxSubArray_divideAndConquer(nums, mid + 1, end);
        //获取中间最大值
        int left_across_mid_max = MIN;
        int left_across_mid_sum = 0;
        for( int i = mid; i >= start; i-- ){
            left_across_mid_sum += nums[i];
            left_across_mid_max = max(left_across_mid_max, left_across_mid_sum);
        }
        int right_across_mid_max = MIN;
        int right_across_mid_sum = 0;
        for( int i = mid + 1; i <= end; i++ ){
            right_across_mid_sum += nums[i];
            right_across_mid_max = max(right_across_mid_max, right_across_mid_sum);
        }
        int across_mid_max = left_across_mid_max + right_across_mid_max;
        return max(left_max, max(right_max, across_mid_max));
    }
};