class Solution {
public:
    const int MAX_INT = 2147483647;
    
    int reverse(int x) {
        /*下述方法只能解决 int 类型的数据，要是 long int 的话就无法解决了
        int reverse_x = 0;
        //将 x 转换为更大的数据范围
        long int li_x = (long int)x;
        long int abs_x = li_x > 0 ? li_x : -li_x;
        long int reverse_x_pre = reverse_x;
        while( abs_x ){
            reverse_x = reverse_x * 10 + abs_x % 10;
            abs_x = abs_x / 10;
            reverse_x_pre = reverse_x;
            //如果 reverse_x_pre * 10 > MAX_INT 且 abs_x还不为0的时候肯定下一次转换会溢出
            if(abs_x && reverse_x_pre * 10 > MAX_INT)
                return 0;
        }
        return x >= 0 ? reverse_x : -reverse_x;*/
        
        
        //根据这次算出来的数 /10 是否与上次循环算出来的数是否一致来判断是否溢出
        int pre_num = 0;
        while (x != 0)
        {
            int n = pre_num * 10 + x % 10;
            x = x / 10;
            //
            if(n / 10 != pre_num) return 0;
            pre_num = n;
        }
        return pre_num;
    }
};