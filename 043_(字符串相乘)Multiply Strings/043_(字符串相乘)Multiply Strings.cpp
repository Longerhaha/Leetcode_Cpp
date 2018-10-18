class Solution {
public:
    string multiply(string num1, string num2) {
        int len_num1 = num1.size();
        int len_num2 = num2.size();
        //输出为0的处理
        if(len_num1 == 0 ||  (len_num1 == 1 && num1 == "0") || len_num2 == 0 || (len_num2 == 1 && num2 == "0")) return "0";
        //反序方便相乘
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
		//先预留第一次乘法位宽
        string ans(len_num1, '0');
        for( int i = 0; i < len_num2; i++ ){
            int carry = 0;
            int len_ans = ans.size();
            for( int j = 0; j < len_num1; j++ ){
                //如果在结果字符串的位宽内则需要与之前的结果相加
                if(i + j < len_ans){
                    //算一位乘一位的乘法
                    int single_product = (num1[j] - '0') * (num2[i] - '0') + carry + ans[i + j] - '0';
                    carry = single_product / 10;
                    ans[i + j] = single_product % 10 + '0';
                }
                //超出结果字符串位宽则在后面添
                else{
                    int single_product = (num1[j] - '0') * (num2[i] - '0') + carry;
                    carry = single_product / 10;
                    ans.push_back(single_product % 10 + '0');
                }
            }
            //如果有进位
            if(carry) ans.push_back(carry + '0');
        }
        //结果反序
        reverse(ans.begin(), ans.end());
        return ans;
    }
};