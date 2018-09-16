class Solution {
public:
    //结合滑窗的动态规划方法
    int totalFruit(vector<int>& tree) {
        int len = tree.size();
        //pre是个长度为2的滑窗，记录最靠近当前位置的两种类型水果的序号
        vector<int> pre(2, -1);
        //dp[i]代表以i为结束位置的采集方法能收集到的水果
        vector<int> dp(len, 0);
        int max_collect = 0;
        for( int i = 0; i < len; i++ ){
            //如果与最接近的两种类型水果都不一样则需要判断能收集到多少水果
            if(tree[i] != pre[0] && tree[i] != pre[1]){
                int search = i - 1;
                //求最接近的类型的水果的连续个数
                while(search >= 0 && (tree[search] == pre[1] || tree[search] == tree[i])) search--;
                //与最接近的类型的水果组合在一起能收集的水果
                dp[i] = i - search;
                //滑动窗口
                pre[0] = pre[1];
                pre[1] = tree[i];
            }
            else{
                //更新为最新的滑窗窗口
                //比如 1 6 5 6 6 这种
                //最新的应该是6而不是5
                if(tree[i] != pre[1]){
                    swap(pre[0], pre[1]);
                }
                //直接在前一个的基础上加1即可
                dp[i] = dp[i - 1] + 1;
            }
            //cout << dp[i] << ":" << pre[0] << " " << pre[1] << endl;
            if(dp[i] > max_collect) max_collect = dp[i];
        }
        return max_collect;
    }
};