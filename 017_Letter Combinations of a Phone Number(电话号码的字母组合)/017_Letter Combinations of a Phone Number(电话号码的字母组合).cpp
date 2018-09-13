class Solution {
public:
    const vector<vector<char>> phone{{}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
                               {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    
    void letterCombinations_dfs(vector<string> &ans, string &digits, int idx, string& path){
        //递归到尾巴的时候保存一下路径
        if(idx == digits.size()){
            ans.push_back(path);
            return ;
        }
        //对所有可能DFS
        for( int j = 0; j < phone[int(digits[idx] - '1')].size(); j++ ){
            path.push_back(phone[int(digits[idx] - '1')][j]);
            letterCombinations_dfs(ans, digits, idx + 1, path);
            path.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0)
            return ans;
        int len = digits.size();
        string path;
        letterCombinations_dfs(ans, digits, 0, path);
        return ans;
    }
};