class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        int words_len = words.size();
        vector<string> ans;
        int k = 0;
        while( k < words_len ){
            //当前行可以容纳的单词的总长度
            int l = 0;
            //从下标为 k 的单词开始查找
            int start = k;
            //先查找当前行可以容纳的单词数
            for( int i = 0; k < words_len && l + words[k].size() < L - i + 1; i++, k++){
                l += words[k].size();
            }
            
            //对当前行进行对齐
            //若是前 x - 1 行左右对齐
            //若是最后一行左对齐并补零
            string str;
            for( int j = start; j < k; j++ ){
                str += words[j];
                if(k < words_len){
                    if(k - start - 1 == 0 || j == k - 1) continue;
                    else str += string(((L - l) / (k - start - 1)) + ((j - start) < ((L - l) % (k - start - 1))), ' ');
                }
                else if(j < k - 1) str += ' ';
            }
            //最后一行有未补齐的空格
            str += string(L - str.size(), ' ');
            ans.push_back(str);
        }
        return ans;
    }
    
};