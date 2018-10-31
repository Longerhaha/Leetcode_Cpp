class Solution {
public:
    //位运算
    string addBinary(string a, string b) {
        string ans;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int len_a = a.size();
        int len_b = b.size();
        bool sum = 0;
        bool carry = 0;
        int i = 0;
        while( i < max(len_a, len_b) || carry ){
            bool bool_a = i >= len_a ? false : (a[i] - '0' > 0);
            bool bool_b = i >= len_b ? false : (b[i] - '0' > 0);
            sum = carry ^ bool_a ^ bool_b;
            ans.push_back(sum + '0');
            carry = (carry & bool_a) | (carry & bool_b) | (bool_a & bool_b);
            i++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};