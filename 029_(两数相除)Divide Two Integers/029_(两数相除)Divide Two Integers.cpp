class Solution {
public:
    const int MAX_INT = 2147483647;
    const int MSB_MASK = 0x80000000; 
    int divide(int dividend, int divisor) {
        //求模
        long int abs_dividend = dividend < 0 ? -((long int)dividend) : dividend;
        long int abs_divisor = divisor < 0 ? -((long int)divisor) : divisor;
        
        if(abs_dividend < abs_divisor) return 0;
        
        //求被除数的最高位
        int msb = 31;
        while( !(abs_dividend & (1 << msb)) ) msb--;
        
        //开始做正整数的除法
        long int R = abs_dividend;//余数
        long int Q = 0;//商
        for( int i = msb; i >= 0; i-- ){
            if((abs_divisor << i) > R) continue;
            Q |= (1 << i);
            R -= (abs_divisor << i);
        }
        //校正
        Q = Q > 0 ? Q : -Q;
        Q = (dividend & MSB_MASK) == (divisor & MSB_MASK) ? Q : -Q;
        Q = Q > MAX_INT ? MAX_INT : Q;
        
        return Q;
    }
};