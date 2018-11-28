class Solution {
public:
    int compress(vector<char>& chars) {
        //强行添加空格方便统一处理
        chars.push_back(' ');
        int len = chars.size();
        int start = 0, search = 1;
        int cnt_same_char = 1, cmpr_len_char = 0;
        while( search < len ){
            if(chars[search] == chars[search - 1]) ++cnt_same_char;
            else{
                chars[cmpr_len_char++] = chars[start];
                //当前char计数值大于1时才压缩
                if(cnt_same_char > 1){
                    //整形转字符串
                    //从高位往低位转 遇见最高位后flag = 1;
                    int flag = 0;
                    int msb = 1000, cnt2char = cnt_same_char;
                    for( int i = 0; i < 4; i++ ){
                        int weight = cnt2char / msb;
                        if(weight > 0 || flag) flag = 1, chars[cmpr_len_char++] = weight + '0';
                        cnt2char = cnt2char % msb;
                        msb = msb / 10;
                    }
                }
                start = search;
                cnt_same_char = 1;
            }
            search++;
        }
        //去除空格，恢复原始数据
        chars.pop_back();
        return cmpr_len_char;
    }
};