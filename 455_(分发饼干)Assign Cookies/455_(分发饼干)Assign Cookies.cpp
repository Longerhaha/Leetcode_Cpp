class Solution {
public:
    //函数中涉及到的c++知识
    //vector<int> 是个长度可变的int数组，c++里面称为容器
    //ret_func_type func(vector<int>& name) 中的name是vector<int>容器的引用，可以理解为传入一个指针
    //sort(g.begin(), g.end()) 对容器g的元素从小到大排序，容器的起始数据的指针是 g.begin(),容器的末尾数据的指针是g.end()
    
    //贪心法
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int len_g = g.size();
        int len_s = s.size();
        //先从小到大排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        //尝试将饼干从小到大分发
        int idx_g = 0, idx_s = 0;
        int cnt_satisfy = 0;
        while( idx_g < len_g && idx_s < len_s ){
            //能满足这个孩子，继续下个饼干发给下一个孩子
            if(g[idx_g] <= s[idx_s]){
                ++cnt_satisfy;
                ++idx_g, ++idx_s;
            }
            //不能满足这个孩子，换个更大的
            else ++idx_s;
        }
        return cnt_satisfy;
    }
};