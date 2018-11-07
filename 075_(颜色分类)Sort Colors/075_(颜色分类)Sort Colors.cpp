class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numsSize = nums.size();
        int i = -1, j = -1, k = -1;//三个指针，i, j, k分别指向最后的0, 1, 2
        //printf("%d %d\n", nums[0], nums[1]);
        for(int l=0; l<numsSize; l++){
            if(0 == nums[l]){
                nums[++k] = 2;
                nums[++j] = 1;
                nums[++i] = 0;
                //printf("%d %d\n", nums[0], nums[1]);
            }
            else if(1 == nums[l]){
                nums[++k] = 2;
                nums[++j] = 1;
            }
            else
                nums[++k] = 2;
        }
    }
};