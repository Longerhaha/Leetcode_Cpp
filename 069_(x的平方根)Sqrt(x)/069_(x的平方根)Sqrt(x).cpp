class Solution {
public:
    //牛顿迭代公式
    double pricision = 0.00001;
    int mySqrt(int x) {
        double y = 1.0 * x;
        double sqrt_y = 1;
        while( abs(y - sqrt_y * sqrt_y) > pricision ){
            sqrt_y = (sqrt_y + y / sqrt_y) / 2;
        }
        return (int)sqrt_y;
    }
};