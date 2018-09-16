class Solution {
public:
    //原地修改
    // odd_begin 记录已重排的数据的第一个奇数的位置
    vector<int> sortArrayByParity(vector<int>& A) {
        int odd_begin = -1;
        for( int i = 0; i < A.size(); i++ ){
            //第一个奇数的位置
            if(odd_begin == -1 && A[i] % 2 == 1){
                odd_begin = i;
            }
            //如果是偶数，则与第一个奇数的位置的数据交换， odd_begin 指向下一个奇数的位置
            else if(odd_begin != -1 && A[i] % 2 == 0){
                swap(A[odd_begin], A[i]);
                odd_begin++;
            }
        }
        return A;
    }
};