class Solution {
public:
    string reverseOnlyLetters(string S) {
        int len = S.size();
        int start = 0, end = len - 1;
        while( start < end ){
            //先跳过非字母字符
            while( start < end && (S[start] < 'A' || (S[start] > 'Z' && S[start] < 'a') || S[start] > 'z') ) start++;
            while( start < end && (S[end] < 'A' || (S[end] > 'Z' && S[end] < 'a') || S[end] > 'z') ) end--;
            swap(S[start], S[end]);
            start++, end--;
        }
        return S;
    }
};