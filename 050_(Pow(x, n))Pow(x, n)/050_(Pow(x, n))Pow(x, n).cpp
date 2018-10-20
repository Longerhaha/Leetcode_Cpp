class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) return 1.0 / unsigned_power(x, -n);
        else return unsigned_power(x, n);
    }
    
    double unsigned_power(double x, int n) {
        if (n == 0) return 1;
        //if (n & 0x01) return x * unsigned_power(x, n / 2) * unsigned_power(x, n / 2);
        //else return unsigned_power(x, n / 2) * unsigned_power(x, n / 2);
        double v = unsigned_power(x, n / 2);
        if (n & 0x01) return x * v * v;
        else return v * v;
    }
};