class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto x : tokens){
            //不是运算符号
            if(x != "+" && x != "-" && x != "*" && x != "/"){
                s.push(stoi(x));
            }
            else{
                //从堆栈取两个出来做运算，并把结果压入堆栈
                int opt2 = s.top();
                s.pop();
                int opt1 = s.top();
                s.pop();
                
                if(x == "+"){
                    s.push(opt1 + opt2);
                }
                else if(x == "-"){
                    s.push(opt1 - opt2);
                }
                else if(x == "*"){
                    s.push(opt1 * opt2);
                }
                else{
                    s.push(opt1 / opt2);
                }
                    
            }
        }
        return s.top();
    }
};