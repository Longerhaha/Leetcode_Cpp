class Solution {
public:
    //回溯法的解空间有基于排列树的解空间，下一个排列就是下一颗树，所以可以根据排列树的结构来解这道题
    //主要有三个步骤
    //1.寻根
    //2.交换
    //3.反序
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        //找根
        int root_idx;
        for( root_idx = len - 2; root_idx >= 0; root_idx-- ){
            if(nums[root_idx + 1] > nums[root_idx]) break;
        }
        //本身就是逆序的，即没有下一个更大的排列
        if(root_idx == -1 || len == 0) return reverse(nums.begin(), nums.end());
        
        //从尾巴开始找，直到找到比 nums[root_idx] 大的数，然后交换二者的值
        for( int i = len - 1; i > root_idx; i-- ){
            if(nums[i] > nums[root_idx]){
                swap(nums[i], nums[root_idx]);
                break;
            }
        }
        //将 nums[root_idx] nums[root_idx + 1] ... nums[len - 1] 反序
        reverse(nums.begin() + root_idx + 1, nums.end());
    }
};

