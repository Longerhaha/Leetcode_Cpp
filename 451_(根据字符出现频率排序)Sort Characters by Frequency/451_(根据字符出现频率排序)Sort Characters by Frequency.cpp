class Solution {
public:
    //函数中涉及到的c++知识
    //vector<int> 是个长度可变的int数组，c++里面称为容器
    //vector<vector<int>> 是个长度可变且长度不一的二维int数组，每行又是一个长度可变的int数组
    //ret_func_type func(vector<int>& name) 中的name是vector<int>容器的引用，可以理解为传入一个指针
    //unordered_map<int, int> map是一个无序哈希表，哈希的键值key是唯一的
    //map[val]就是获得val在哈希表map中的个数
    
    string frequencySort(string s) {
        unordered_map<char, int> map;
        //1. 先插入哈希表
        for( int i = 0; i < s.size(); i++ ) map[s[i]]++;
        
        vector<vector<int>> bucket(s.size());
        //2. 桶排序
        //it->second是字符出现的个数，it->first是字符
        for (auto it = map.begin(); it != map.end(); ++it) bucket[it->second - 1].push_back(it->first);
        //3. 遍历桶
        string ans;
        for( int i = bucket.size() - 1; i >= 0; i-- ){
            if(bucket[i].size() != 0){
                for( int j = 0; j < bucket[i].size(); j++ ){
                    ans.insert(ans.end(), i+1, bucket[i][j]);
                }
            }
        }
        return ans;
    }
};