class Solution {
public:
    //函数中涉及到的c++知识
    //vector<char> 是个长度可变的 char 数组，c++里面称为容器
    //vector<int> 是个长度可变的 int 数组，c++里面称为容器
    //vector<int> dict(26, 0) 初始化包含26个元素的可变数组为0
    char nextGreatestLetter(vector<char>& letters, char target) {
        //字符初始化为未出现
        vector<int> dict(26, 0);
        //一遍扫描记录出现的字符
        int cnt_valid_letter = 0;
        int len = letters.size();
        for( int i = 0; i < len; i++ ){
            if(cnt_valid_letter == 26) continue;
            if(dict[letters[i] - 'a'] == 0){
                dict[letters[i] - 'a'] = 1;
                cnt_valid_letter++;
            }
        }
        //环形扫描比目标字母大的最小字母
        int start = (target - 'a' + 1) % 26;
        for( int i = 0; i < 26; i++ ){
            if(dict[(i+start)%26]) return ((i+start)%26+'a');
        }
        return -1;
    }
};