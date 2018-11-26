class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int start = 0, end = len - 1;
        while( start < end ){
            //跳过无效字符
            while(start < end && (s[start] < '0' || (s[start] > '9' && s[start] < 'A') ||  (s[start] > 'Z' && s[start] < 'a') || s[start] > 'z')) start++;
            while(start < end && (s[end] < '0' || (s[end] > '9' && s[end] < 'A') ||  (s[end] > 'Z' && s[end] < 'a') || s[end] > 'z')) end--;
            //cout << start << " " << end << endl;
            //比较是否对称
            if(((s[start] >= '0' && s[start] <= '9') || (s[end] >= '0' && s[end] <= '9')) && s[start] != s[end]) return false;
            if(s[start] != s[end] && abs(s[start] - s[end]) != 32) return false;
            start++, end--;
        }
        return true;
    }
};