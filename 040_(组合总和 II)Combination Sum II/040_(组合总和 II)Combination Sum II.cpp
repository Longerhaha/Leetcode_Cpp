class Solution {
public:
    void combinationSum2_DFS(vector<vector<int> > &ans, vector<int> &num, vector<int> &path, int target, int start){
        if(target < 0) return ;
        else if(target == 0){
            ans.push_back(path);
            return;
        }
        for( int i = start; i < num.size(); i++ ){
            if(i > start && num[i] == num[i - 1]) continue;
            path.push_back(num[i]);
            combinationSum2_BackTrack(ans, num, path, target - num[i], i + 1);
            path.pop_back();
        }
    }
    
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        vector<int> path;
        combinationSum2_DFS(ans, num, path, target, 0);
        return ans;
    }
    
};
