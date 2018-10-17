class Solution {
public:
    int trap(vector<int>& height) {
        //左右边界一遍扫描法
        int len_height = height.size();
        int left_max_idx = 0, right_max_idx = len_height - 1;
        int left = 0, right = len_height - 1;
        int collect_drop = 0;
        while( left < right ){
            if(height[left_max_idx] < height[right_max_idx]){
                left++;
                if(height[left] > height[left_max_idx]) left_max_idx = left;
                else collect_drop += height[left_max_idx] - height[left];
            }
            else{
                right--;
                if(height[right] > height[right_max_idx]) right_max_idx = right;
                else collect_drop += height[right_max_idx] - height[right];
            }
        }
        return collect_drop;
    }
};