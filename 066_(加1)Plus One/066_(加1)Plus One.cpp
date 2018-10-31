class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        reverse(digits.begin(), digits.end());
        int len = digits.size();
        int carry = 1;
        int sum = 0;
        for( int i = 0; i < len; i++ ){
            sum = (digits[i] + carry) % 10;
            ans.push_back(sum);
            carry = (digits[i] + carry) >= 10;
        }
        if(carry) ans.push_back(1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};