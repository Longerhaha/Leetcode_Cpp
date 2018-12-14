class Solution {
public:
    //函数中涉及到的c++知识
    //vector<int> 是个长度可变的int数组，c++里面称为容器
    //vector<vector<int>> 是个长度可变且长度不一的二维int数组，每行又是一个长度可变的int数组
    //ret_func_type func(vector<int>& name) 中的name是vector<int>容器的引用，可以理解为传入一个指针
    //unordered_map<int, int> map是一个无序哈希表，哈希的键值key是唯一的
    //map[val]就是获得val在哈希表map中的个数
    
    
    
    //时间复杂度O(n) 哈希表+桶排序
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1. 先把数组所有元素插入哈希表
        unordered_map<int, int> map;
        for( int i = 0; i < nums.size(); i++ ) map[nums[i]]++;
        //2. 遍历哈希表，插入桶中
        //桶的下标是哈希表关键字的个数, 桶的值是哈希表的关键字
        vector<vector<int>> bucket(nums.size());
        //it->second是关键字的个数，it->first是哈希表的关键字
        for (auto it = map.begin(); it != map.end(); ++it) bucket[it->second - 1].push_back(it->first);
        
        //3. 从桶末尾开始遍历桶直到取得桶的高k位数据
        vector<int> ans;
        int ans_num = 0;
        for( int i = nums.size() - 1; i >= 0; i-- ){
            if(bucket[i].size() != 0){
                for( int j = 0; j < bucket[i].size(); j++ ){
                    ans.push_back(bucket[i][j]);
                    if(++ans_num == k) return ans;
                }
            }
        }
        //出错
        return {-1};
    }
};