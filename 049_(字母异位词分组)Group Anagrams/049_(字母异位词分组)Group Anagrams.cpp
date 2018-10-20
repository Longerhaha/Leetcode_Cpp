class Solution {
public:
    //基于字符计数的分类法
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //分组的矢量
        vector<vector<string>> groups;
        //利用 map 来分组
        unordered_map<string, vector<string>> map;
        int len_strs = strs.size();
        for( int i = 0; i < len_strs; i++ ){
            //字符计数的结果作为 key
            string str_cnt(26, '0');
            for( int j = 0; j < strs[i].size(); j++ ) str_cnt[strs[i][j] - 'a']++;
            if(map.count(str_cnt) == 0){
                vector<string> group;
                map[str_cnt] = group;
            }
            auto it = map.find(str_cnt);
            (it->second).push_back(strs[i]);
        }
        
        unordered_map<string, vector<string>>::iterator iter;
        for( iter = map.begin(); iter != map.end(); iter++ ){
            groups.push_back(iter->second);
        }
        return groups;
    }
};