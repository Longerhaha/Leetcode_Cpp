class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        //1. 算 A 数组的和、B数组的和并将B数组的数据存入集合set
        int sumA = 0;
        for( auto a : A ) sumA += a;
        unordered_set<int> set;
        int sumB = 0;
        for( auto b : B ) sumB += b, set.insert(b);
        //2. 算 A 数组的和与B数组的和的差值
        
        int diff = sumB - sumA;
        //3. 遍历A，查找加上A[i] + diff / 2是否在B的集合里，如果在则记录并返回
        for( int i = 0; i < A.size(); i++ ){
            if(set.count(A[i] + diff / 2) > 0){
                ans.push_back(A[i]);
                ans.push_back(A[i] + diff / 2);
                return ans;
            }
        }
        return ans;
    }
};