class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> ans;
        //1. 提取单词
        vector<string> strA;
        int startA = 0;
        for( int i = 0; i < A.size(); i++ ){
            if(A[i] == ' '){
                strA.push_back(A.substr(startA, i - startA));
                startA = i + 1;
            }
            else if(i == A.size() - 1){
                strA.push_back(A.substr(startA, i - startA + 1));
            }
        }
        vector<string> strB;
        int startB = 0;
        for( int i = 0; i < B.size(); i++ ){
            if(B[i] == ' '){
                strB.push_back(B.substr(startB, i - startB));
                startB = i + 1;
            }
            else if(i == B.size() - 1){
                strB.push_back(B.substr(startB, i - startB + 1));
            }
        }
        //2. 单词加入 multiset 中
        unordered_multiset<string> setA;
        unordered_multiset<string> setB;
        for( auto str : strA ) setA.insert(str);
        for( auto str : strB ) setB.insert(str);

        //3. 判断是否是不常见的单词
        for( auto str : strA){
            cout << str << ":" << setA.count(str) << endl;
            if(setA.count(str) == 1 && setB.count(str) <= 0)
                ans.push_back(str);
        }
        for( auto str : strB){
            if(setB.count(str) == 1 && setA.count(str) <= 0)
                ans.push_back(str);
        }
        
        return ans;
    }
};