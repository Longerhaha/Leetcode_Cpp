class Solution {
public:
    string countAndSay(int n) {
        string pre = "1";
        if(n == 1) return pre;
        for( int i = 2; i <= n; i++){
            //至少有一个，所以 cnt 初始化为 1
            int cnt = 1;
            string cur;
            for(  int j = 0; j < pre.size(); j++ ){
                //扩大连续的范围
                if(j + 1 < pre.size() && pre[j] == pre[j + 1]) cnt++;
                //搜索到不相同则记录
                else{
                    char cnt_char = cnt + '0';
                    cur.push_back(cnt_char);
                    cur.push_back(pre[j]);
                    cnt = 1;
                }
            }
            //更替
            pre = cur;
            if(i == n) return cur;
        }
    }
};