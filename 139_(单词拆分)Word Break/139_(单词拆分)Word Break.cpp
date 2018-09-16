class Solution {
public:
    /*
    bool wordBreak(string s, vector<string>& wordDict) {
        queue<string> q;
        unordered_map<string, int> ump;
        //1.先将单词列表添加哈希表内
        for( int i = 0; i < wordDict.size(); i++ ){
            ump[wordDict[i]] = 1;
        }
        //2.查找是否可以拆分的可能
        q.push(s);
        while( !q.empty() ){
            string tmp = q.front();
            q.pop();
            if(ump.count(tmp) > 0)
                return true;
            for( int i = 1; i < tmp.size(); i++ ){
                string sub_str = tmp.substr(0, i);
                if(ump.count(sub_str) > 0){
                    q.push(tmp.substr(i, tmp.size() - i));
                }
            }
        }
        return false;
    }*/
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> uset;
        //1.先将单词列表添加集合内
        for( int i = 0; i < wordDict.size(); i++ ){
            uset.insert(wordDict[i]);
        }
        //dp[i]代表从s[0]...s[i]是可以拆分的
        //dp[k] = ((dp[x] && wordDict.contains(s.substr(x + 1, x - j))  x = 1....k-1) || wordDict.contains(s.substr(0, k)))
        
        int len = s.size();
        vector<int> dp(len , 0);
        for( int i = 0; i < len; i++ ){
            //cout << s.substr(0, i + 1) << endl;
            if(uset.count(s.substr(0, i + 1)) > 0){
                dp[i] = 1;
                continue;
            }
            else{
                for( int j = 0; j < i; j++ ){
                    if(dp[j] && uset.count(s.substr(j + 1, i - j))){
                        dp[i] = 1;
                        break;
                    }
                }
            }
            //cout << dp[i] << endl;
        }
        return dp[len - 1];
    }
};