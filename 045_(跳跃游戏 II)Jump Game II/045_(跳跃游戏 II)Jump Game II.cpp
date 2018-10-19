class Solution {
public:
    //贪心算法
    int jump(vector<int>& nums) {
        int len_nums = nums.size();
        if(len_nums == 1) return 0;
        int step = 0;
        //当前 step 的 max_distance
        int max_distance = 0 ;
        //当前 step 的 max_distance 内所能跳跃的最大距离
        int cur_step_max_distance = 0;
        for( int i = 0; i < len_nums; i++ ){
            //搜索到当前 step 所能跳跃的最大距离
            if(i == max_distance){
                //跳跃一步，并求出下一步的最大距离
                step++;
                max_distance = max(cur_step_max_distance, i + nums[i]);
                if(max_distance >= len_nums - 1) return step;
            }
            else{
                //搜索当前step范围内的最远距离
                cur_step_max_distance = max(cur_step_max_distance, i + nums[i]);
                if(cur_step_max_distance >= len_nums - 1) return ++step;
            }
        }
    }
};