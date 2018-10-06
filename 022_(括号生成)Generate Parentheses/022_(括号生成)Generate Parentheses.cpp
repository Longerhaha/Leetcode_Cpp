class Solution {
public:
    void generateParenthesis_dfs(vector<string> &ans, string path, int left, int right){
        if(left == 0 && right == 0){
            ans.push_back(path);
            return ;
        }
        if(left > 0){
            generateParenthesis_dfs(ans, path + '(', left - 1, right + 1);
        }
        if(right > 0){
            generateParenthesis_dfs(ans, path + ')', left, right - 1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        generateParenthesis_dfs(ans, path, n, 0);
        return ans;
    }
};