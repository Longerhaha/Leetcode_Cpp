class Solution {
public:
    //函数中涉及到的c++知识
    //pair<int, int> tmp可以理解为含有两个int变量的结构体数组，其第1个元素为tmp.first, 第2个元素为tmp.second
    //vector<pair<int, int>> 是个长度可变的结构体(含有两个int变量)数组，c++里面称为容器
    //ret_func_type func(vector<pair<int, int>>& name) 中的name是vector<pair<int, int>>容器的引用，可以理解为传入一个指针
    //sort(g.begin(), g.end()) 对容器g的元素从小到大排序，容器的起始数据的指针是 g.begin(),容器的末尾数据的指针是g.end()
    
    //贪心法
    //1. 先按右边界从大到小排序
    //2. 确定贪心准则：在区间的右边界引爆气球
    //   然后遍历区间
    //     * 若当前区间的左边界大于上一次引爆的地方，说明进入了爆破后的非重复区域，此时继续在其右边界引爆
    //     * 否则说明其依旧处于当前爆破点的爆破范围            
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0) return 0;
        int cnt_arrow = 1;
        sort(points.begin(), points.end(), cmp);
        int last_end = points[0].second;
        for( int i = 1; i < points.size(); i++ ){
            if(points[i].first > last_end){
                cnt_arrow++;
                last_end = points[i].second;
            }
        }
        return cnt_arrow;
    }
    
    static bool cmp(const pair<int, int>& point1, const pair<int, int>& point2){
        return point1.second < point2.second;
    }
};