class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //键是字符串，键值是深度
        unordered_map<string, int> umap;
        //存储单词的字典
        unordered_set<string> dict;
        for( auto x : wordList)
            dict.insert(x);
        //去除字典中的 beginWord
        dict.erase(beginWord);
        
        //先把 beginWord 加入队列
        umap[beginWord] = 1;
        queue<string> q;
        q.push(beginWord);
        //BFS
        while( !q.empty() ){
            //先弹出队列中一个元素
            string str = q.front();
            q.pop();
            //如果与endWord相等
            if(endWord.compare(str) == 0)
                return umap[str];
            
            int depth = umap[str];
            for( int i = 0; i < str.size(); i++ ){
                //记录i位置的字符
                char old_str = str[i];
                //遍历该位置其他可能的字符
                for( char x = 'a' ; x <= 'z'; x++ ){
                    if(x != old_str){
                        //替换该位置的单词为x
                        str.replace(i, 1, 1, x);
                        //如果该单词在字典中，记录深度、进队并从字典中删去，防止BFS时多次遍历
                        if(dict.count(str) > 0){
                            umap[str] = depth + 1;
                            q.push(str);
                            dict.erase(str);
                        }
                    }
                }
                //恢复i位置的字符
                str[i] = old_str;
            }
        }
        return 0;

    }

};