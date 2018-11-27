class Solution {
public:
    //1.翻转
    //2.按单词反转
    void reverseWords(string &s) {
        //强行头部加空格方便统一处理
        s.insert(0, 1, ' ');
        reverse(s.begin(), s.end());
        int len = s.size();
        //搜索的位置
        int search = 0;
        //搜索的当前单词的长度
        int cnt_word = 0;
        //搜索的当前单词的起始位置
        int start_word = 0;
        while( search < len ){
            //在单词有效范围内
            if(s[search] != ' ') ++search, ++cnt_word;
            //在单词边界
            else{
                if(cnt_word != 0){
                    //翻转单词
                    reverse(s.begin() + start_word, s.begin() + start_word + cnt_word);
                    //去除多余的空格
                    search++;
                    while(search < len && s[search] == ' ') s.erase(s.begin() + search);
                    //设置下一个单词搜索的初始位置和长度
                    start_word = search;
                    cnt_word = 0;
                }
                //可以去除原字符串中开头和尾巴可能存在的连续空格
                else s.erase(s.begin() + start_word);
            }
        }
        //去除空格最后一个单词附带的空格
        s.pop_back();
    }
};