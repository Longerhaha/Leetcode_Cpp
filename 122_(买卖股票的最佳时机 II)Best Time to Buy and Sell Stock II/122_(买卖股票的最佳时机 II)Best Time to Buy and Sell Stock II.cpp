class Solution {
public:
    //函数中涉及到的c++知识
    //vector<int> 是个长度可变的 int 数组，c++里面称为容器
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int max_profit = 0;
        for( int i = 1; i < len; i++ ){
            if(prices[i] - prices[i - 1] > 0) max_profit += prices[i] - prices[i - 1];
        }
        return max_profit;
    }
};