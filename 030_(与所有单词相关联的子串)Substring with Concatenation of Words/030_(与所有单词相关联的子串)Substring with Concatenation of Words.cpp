class Solution {
public:
    //滑窗搜索
    vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> res;
        int len_s = s.size();
        int len_words = words.size();
        if(len_s == 0 || len_words == 0) return res;
        int len_word = words[0].size();
        
        //添加字典
        unordered_map<string, int> word_dict;
        for( auto word : words ) ++word_dict[word];
        //由于单词 words 长度固定，可以把 s 分成len_word 个部分
        //每个部分间隔 len_word 去搜索
        //比如 abcedfsadsd
        //分成 a  e  s  s
        //      b  d  a  d
        //       c  f  d
        for( int i = 0; i < len_word; i++ ){
            unordered_map<string, int> match_dict;
            int start = i;
            int cnt = 0;
            for( int j = i; j <= len_s - len_word; j += len_word ){
                string cur_str = s.substr(j, len_word);
                if(word_dict.count(cur_str) > 0){
                    ++match_dict[cur_str];
                    cnt++;
                    if(match_dict[cur_str] <= word_dict[cur_str]){
                        if(cnt == len_words){
                            res.push_back(start);
                            cnt--;
                            //滑窗搜索
                            --match_dict[s.substr(start, len_word)];
                            start += len_word;
                        }
                    }
                    else{  
                        //窗口调整为最大匹配的窗
                        while(match_dict[cur_str] > word_dict[cur_str]){
                            --match_dict[s.substr(start, len_word)];
                            --cnt;
                            start += len_word;
                        }
                    }
                }
                else{
                    start = j + len_word;
                    cnt = 0;
                    match_dict.clear();
                }
            }
        }
        return res;
	}
};