class Solution {
public:
    void combinationSum_DFS(vector<vector<int>>& ans, vector<int>& path, vector<int>& candidates, int target, int start){
        if(target == 0){
            ans.push_back(path);
            return ;
        }
        else if(target < 0) return ;

        for( int i = start; i < candidates.size(); i++ ){
            path.push_back(candidates[i]);
            combinationSum_DFS(ans, path, candidates, target - candidates[i], i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        combinationSum_DFS(ans, path, candidates, target, 0);
        return ans;
    }
    
};
