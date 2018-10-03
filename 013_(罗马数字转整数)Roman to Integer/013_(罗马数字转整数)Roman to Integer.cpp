class Solution {
public:
    //const weight[6] = {1, 5, 10, 50, 100, 500, 1000};
    int romanToInt(string s) {
        unordered_map<char, int> mp {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int conversion = 0;
        
        int len_s = s.size();
        for( int i = 0; i < len_s; i++ ){
            if(s[i] == 'C' && (i + 1) < len_s){
                if(s[i + 1] == 'D' || s[i + 1] == 'M')
                    conversion -= 100;
                else
                    conversion += 100;
            }
            else if(s[i] == 'X' && (i + 1) < len_s){
                if(s[i + 1] == 'L' || s[i + 1] == 'C')
                    conversion -= 10;
                else
                    conversion += 10;
            }
            else if(s[i] == 'I' && (i + 1) < len_s){
                if(s[i + 1] == 'V' || s[i + 1] == 'X')
                    conversion -= 1;
                else
                    conversion += 1;
            }
            else conversion += mp[s[i]];
        }
        return conversion;
    }
};