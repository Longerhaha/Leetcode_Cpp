class Solution {
public:
    const int MOD = 1000000007;
    int sumSubarrayMins(vector<int>& A) {
        int len = A.size();
        /*
         这种方法不行，最坏的情况有O（n^2）
        int left = 0, right = 0;
        int sum = 0;
        for( int i = 0; i < len; i++ ){
            left = i - 1;
            while( left >= 0 && A[left] >= A[i] ) left--;
            right = i + 1;
            while( right < len && A[right] > A[i]) right++;
            
            int left_cnt = i - left;
            int right_cnt = right - i;
            //cout << left_cnt << " " << right_cnt << endl;
            sum += (right_cnt * left_cnt * A[i]) % MOD;
            sum = sum % MOD;
        }*/
        vector<int> left(len, -1);
        vector<int> right(len, -1);
        //从右往左找与他相等或者比他大的数有几个，包括他自己
        for( int i = 0; i < len; i++ ){
            int pre_pos = i - 1;
            while( pre_pos >= 0 && A[i] <= A[pre_pos]) pre_pos -= left[pre_pos];
            left[i] = i - pre_pos;
        }
        //从左往右找找比他大的数有几个，包括他自己
        //这里没有等号的原因是：可能有相等的数据，则右往左找的时候统计一次，左往右找的时候统计一次，统计了多次
        for( int i = len - 1; i >= 0; i-- ){
            int next_pos = i + 1;
            while( next_pos < len && A[i] < A[next_pos]) next_pos += right[next_pos];
            right[i] = next_pos - i;
        }
         
        //以A[i]为最小值的子序列的可能性有 left[i] * right[i] 种
        //对所有情况进行累加即可
        int sum = 0;
        for( int i = 0; i < len; i++ ){
            //cout << left[i] << " " << right[i] << endl;
            sum = (sum + left[i] * right[i] * A[i]) % MOD;
        }
        return sum;
    }
};