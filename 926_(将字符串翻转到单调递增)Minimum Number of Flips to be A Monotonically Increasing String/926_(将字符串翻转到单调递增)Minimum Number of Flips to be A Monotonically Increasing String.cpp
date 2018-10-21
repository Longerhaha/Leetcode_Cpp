class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int len_S = S.size();
        int zero_num = 0;
        for( auto s : S ) zero_num += s == '0' ? 1 : 0;
        //遍历所有的位置，算当前位置前（包括当前位置）的1变0和当前位置后（不包括当前位置）的0变1总共需要的步数，此时变化后为一个递增序列
        int zero_flip = zero_num;
        int one_flip = 0;
        int min_flip = zero_num + 0;
        for( int i = 0; i < len_S; i++ ){
            if(S[i] == '0') zero_flip--;
            else one_flip++;
            min_flip = min(min_flip, zero_flip + one_flip);
        }
        return min_flip;
    }
};