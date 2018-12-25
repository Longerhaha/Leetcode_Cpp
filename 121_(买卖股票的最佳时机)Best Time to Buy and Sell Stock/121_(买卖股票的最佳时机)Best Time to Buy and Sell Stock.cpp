class Solution {
public:
    //函数中涉及到的c++知识
    //vector<int> 是个长度可变的 int 数组，c++里面称为容器
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        //边界情况
        if(len == 0) return 0;
        
        //当前最大的利益 = max(前一天可能的最大利益, 今天的价钱-最低价)
        int max_profit = -2147483648;
        int min_price = 2147483647;
        for( int i = 0; i < prices.size(); i++ ){
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};