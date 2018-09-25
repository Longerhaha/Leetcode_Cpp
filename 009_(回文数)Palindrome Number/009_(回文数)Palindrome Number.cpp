class Solution {
public:
    bool isPalindrome(int x) {
        if( x < 0) return false;
        
        //求逆序所代表的数的大小
        int x_tmp = x;
        int opposite_x = 0;
        while( x_tmp ){
            opposite_x = opposite_x * 10 + x_tmp % 10;
            x_tmp /= 10;
        }
        return opposite_x == x;
    }
};