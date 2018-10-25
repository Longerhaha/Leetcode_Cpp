class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        //num 为字符串"123...n"
        string num;
        for( int i = 1; i <= n; i++ ) num += (i + '0');
        //先算 (n - 1)!
        int rank = 1;
        for( int i = n - 1; i >= 1; i-- ) rank *= i;
        //k - 1方便与数组下标对应
        k--;
        //迭代求从高位到低位的数字
        for( int i = n - 1; i >= 1; i-- ){
            int idx = k / rank;
            ans += num[idx];
            //删除该字符后，此时 num 仍然是有序的
            num.erase(idx, 1);
            k = k - idx * rank;
            rank = rank / i;
        }
        ans += num[k];
        return ans;
    }
};