class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> ans;
        int A_len = A.size();
        int total_1 = 0;
        for(auto a : A) total_1 += a;
        
        //输入全0或者不能三分
        if(total_1 % 3 != 0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else if(total_1 == 0){
            ans.push_back(0);
            ans.push_back(A_len - 1);
            return ans;
        }
        
        //求第三部分结尾的0的个数
        int cnt_third_tail_zero = 0;
        int third_tail_zero_idx = A_len - 1;
        while( A[third_tail_zero_idx] == 0 ){
            cnt_third_tail_zero++;
            third_tail_zero_idx--;
        }
        
        //遍历求切割的下标，切割的目标是将1等分
        int cut1, cut2;
        int cnt = 0;
        int idx = 0;
        while( idx < A_len ){
            cnt += A[idx];
            //第一段
            if(cnt == total_1 / 3){
                //比较第一部分尾巴的0与第三部分包含的尾部的0
                //如果小于则说明无法找到这样子的三分法
                int cnt_first_tail_zero = 0;
                while(cnt_first_tail_zero < cnt_third_tail_zero && A[++idx] == 0) cnt_first_tail_zero++; 
                if(cnt_first_tail_zero < cnt_third_tail_zero){
                    ans.push_back(-1);
                    ans.push_back(-1);
                    return ans;
                }
                else cut1 = idx;
                //跨越第二段开始的0
                while(A[++idx] == 0);
            }
            //第二段
            else if(cnt == total_1 * 2 / 3){
                //比较第二部分尾巴的0与第三部分包含的尾部的0
                //如果小于则说明无法找到这样子的三分法
                int cnt_second_tail_zero = 0;
                while(cnt_second_tail_zero < cnt_third_tail_zero && A[++idx] == 0) cnt_second_tail_zero++; 
                if(cnt_second_tail_zero < cnt_third_tail_zero){
                    ans.push_back(-1);
                    ans.push_back(-1);
                    return ans;
                }
                else cut2 = idx + 1;
                //跨越第三段开始的0
                while(A[++idx] == 0);
            }
            else{
                idx++;
            }

        }
        
        //比较切割的三个含有相等的1的部分是否是相等的
        int start1 = 0;
        int start2 = cut1 + 1;
        int start3 = cut2;
        
        
        //跳跃0
        while(A[start1] == 0) start1++;
        while(A[start2] == 0) start2++;
        while(A[start3] == 0) start3++;
        
        //长度相等且内容相等
        if(cut1 - start1 + 1 == cut2 - start2 && cut1 - start1 + 1 == A_len - start3 && memcmp(&A[0] + start1, &A[0] + start2, cut1 - start1 + 1) == 0 && memcmp(&A[0] + start1, &A[0] + start3, cut1 - start1 + 1) == 0){
            ans.push_back(cut1);
            ans.push_back(cut2);
        }
        else{
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;
    }
};