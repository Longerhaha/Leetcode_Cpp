# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 452_(用最少数量的箭引爆气球)Minimum Number of Arrows to Burst Balloons
## 1 问题描述、输入输出与样例
### 1.1 问题描述
在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以y坐标并不重要，因此只要知道开始和结束的x坐标就足够了。开始坐标总是小于结束坐标。平面内最多存在104个气球。<br>

一支弓箭可以沿着x轴从不同点完全垂直地射出。在坐标x处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 <br>弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。
### 1.2 输入与输出
输入：
* vector<pair<int, int>>& points:气球直径坐标的列表

输出：
* int:最少数量的箭
### 1.3 样例
#### 1.3.1 样例1
输入:[[10,16], [2,8], [1,6], [7,12]]<br>
输出:2<br>
解释:对于该样例，我们可以在x = 6（射爆[2,8],[1,6]两个气球）和 x = 11（射爆另外两个气球）。

## 2 思路描述与代码	
### 2.1 思路描述（贪心法）
1. 先按右边界从大到小排序
2. 确定贪心准则：在区间的右边界引爆气球可以使用最少数量的箭引爆气球
   然后遍历区间
   * 若当前区间的左边界大于上一次引爆的地方，说明进入了爆破后的非重复区域，此时继续在其右边界引爆
   * 否则说明其依旧处于当前爆破点的爆破范围 


比如输入:points = [[10,16], [2,8], [1,6], [7,12]]；<br>
last_end 记录上一次引爆的右边界，cnt 记录爆破的次数；<br>
1. 以右边界排序后有：points = [[1,6], [2,8], [7,12], [10,16]]；<br>
2. 遍历区间:
    * 区间[1,6], 在其右边界引爆气球, last_end = 6，cnt = 1；<br>
    * 区间[2:8], 2 < last_end, 仍处于可爆破的地方, last_end = 8，cnt = 1；<br>
    * 区间[7,12], 7 > last_end, 在其右边界引爆气球, last_end = 12，cnt = 2；<br>
    * 区间[10,16], 10 < last_end, 仍处于可爆破的地方, last_end = 12，cnt = 2；<br>
于是返回2。
### 2.2 代码
```cpp
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
```
## 3 思考与拓展
### 3.1 思考
本题的关键在于以右边从小到大排序，然后贪心准则(在区间的右边界引爆气球可以使用最少数量的箭引爆气球)才是对的。
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
贪心法|O(1)|O(nlogn)

#### 3.1.3 难点分析
1. 确定以右边界对气球区间从小到大排序;
2. 确定贪心准则：在区间的右边界引爆气球可以使用最少数量的箭引爆气球。

### 3.2 拓展
本题如果以左边界对气球区间从小到大排序、以同样的贪心准则会出现什么问题？

	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
