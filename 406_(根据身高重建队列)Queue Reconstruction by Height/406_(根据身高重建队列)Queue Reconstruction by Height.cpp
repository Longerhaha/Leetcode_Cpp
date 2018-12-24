class Solution {
public:
    //函数中涉及到的c++知识
    //pair<int, int> 可以理解为包含两个元素的结构体
    //vector<pair<int, int>> 是个长度可变的结构体数组，c++里面称为容器
    //ret_func_type func(vector<pair<int, int>>& name) 中的name是vector<pair<int, int>>容器的引用，可以理解为传入一个指针
    //sort(g.begin(), g.end(), cmp) 对容器g的结构体按照cmp的排序规则排序，容器的起始数据的指针是 g.begin(),容器的末尾数据的指针是g.end()

    //1. 按身高 h 从大到小排列，身高相等按 k 从小到大排序
    //2. 重建队列
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int len = people.size();
        vector<pair<int, int>> ans;
        //1. 按身高 h 从大到小排列，身高相等按 k 从小到大排序
        sort(people.begin(), people.end(), cmp);
        //2. 重建队列
        for( int i = 0; i < len; i++ ){
            ans.insert(ans.begin() + people[i].second, people[i]);
        }
        return ans;
    }
    //按身高 h 从大到小排列，身高相等按 k 从小到大排序
    static bool cmp(const pair<int, int>& data1, const pair<int, int>& data2){
        return data1.first != data2.first ? data1.first > data2.first : data1.second < data2.second;
    }
};