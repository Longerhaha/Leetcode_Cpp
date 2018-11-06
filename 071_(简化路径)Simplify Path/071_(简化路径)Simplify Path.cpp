class Solution {
public:
    string simplifyPath(string path) {
        string ans;
        int len = path.size();
        int search = 0;
        vector<string> simplifyPathWord;
        while( search < len ){
            while(search < len && path[search] == '/') search++;
            string word;
            while(search < len && path[search] != '/') word += path[search++];
            if(word.size() == 0 || word.compare(".") == 0) continue;
            else if(word.compare("..") == 0){
               if(simplifyPathWord.size() != 0) simplifyPathWord.pop_back(); 
            }
            else simplifyPathWord.push_back(word);
        }
        
        if(simplifyPathWord.size() == 0) return "/";
        else{
            for( int i = 0; i < simplifyPathWord.size(); i++ ){
                ans += '/';
                ans += simplifyPathWord[i];
            }
            return ans;
        }
        
    }
};