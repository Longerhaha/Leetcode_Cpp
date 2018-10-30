class Solution {
public:
    /*  我们把有效的数字统一为如下两种模式：
        1. 空格串（可选） + 底数的整数部分 + 底数的小数部分（可选） + 指数（可选） + 空格串（可选）
        2. 空格串（可选） + 底数的小数部分 + 指数（可选） + 空格串（可选）
        除去开头空格串，第 1 种方式有8种情况，第 2 中方式有4种情况。分别如下：
        1. 底数的整数部分
        2. 底数的整数部分 + 空格串
        3. 底数的整数部分 + 指数 
        4. 底数的整数部分 + 指数 + 空格串
        5. 底数的整数部分 + 底数的小数部分
        6. 底数的整数部分 + 底数的小数部分 + 空格串
        7. 底数的整数部分 + 底数的小数部分 + 指数
        8. 底数的整数部分 + 底数的小数部分 + 指数 + 空格串
        9. 底数的小数部分 
        10. 底数的小数部分 + 空格串
        11. 底数的小数部分 + 指数
        12. 底数的小数部分 + 指数 + 空格串  */
    bool isNumber(string s) {
        int len = s.size();
        int search = 0;
        //1. 先跳过空格
        while( search < len && s[search] == ' ') search++;
        if(search == len) return false;
        //2. 跳过符号位
        if(search < len && (s[search] == '-' || s[search] == '+')) search++;
        //3. 检查经过上述两个步骤后的输入是不是合法的，如果合法则能够进入状态0进行后续操作，如果不合法输出false
        //能进入状态0的情况有：
        //(1)数字开头
        //(2)小数点开头且小数点后的第一位是数字
        if((s[search] >= '0' && s[search] <= '9') || (search + 1 < len && s[search] == '.' &&  s[search + 1] >= '0' && s[search + 1] <= '9' )) ;
        else return false;
        
        //设置状态机
        //其中状态 0 表示搜索底数的整数部分(保证存在，但不知道是不是有效的)
        //状态 1 表示搜索底数的小数部分(保证存在，但不知道是不是有效的)
        //状态 2 表示搜索指数部分(保证存在，但不知道是不是有效的)
        int state = 0;
        while( search < len ){
            switch(state){
                case 0: {
                    if(s[search] == ' '){
                        //类型：底数的整数部分 + 空格串
                        while( search < len && s[search] == ' ') search++;
                        if(search == len) return true;
                        else return false;
                    }
                    else if(s[search] == '.'){
                        // 类型：底数的整数部分
                        if(search == len - 1) return true;
                        // 跳到状态1
                        else if(s[search + 1] != ' ' && s[search + 1] != 'e' && s[search + 1] != 'E' && (s[search + 1]  < '0' || s[search + 1] > '9')) return false;
                        state = 1;
                    }
                    // 跳到状态2
                    else if(s[search] == 'e' || s[search] == 'E'){
                        if(search + 1 < len && (s[search + 1] == '-' || s[search + 1] == '+')) search++;
                        if(search == len - 1 || (s[search + 1]  < '0' || s[search + 1] > '9')) return false;
                        state = 2;
                    }
                    else if(s[search] < '0' || s[search] > '9') return false;
                    search++;
                    break;
                }
                case 1:{
                    if(s[search] == ' '){
                        //类型：底数的整数部分 + 底数的小数部分 + 空格串
                        //类型：底数的小数部分 + 空格串
                        while( search < len && s[search] == ' ') search++;
                        if(search == len) return true;
                        else return false;
                    }
                    //跳转至状态2
                    else if(s[search] == 'e' || s[search] == 'E'){
                        if(search + 1 < len && (s[search + 1] == '-' || s[search + 1] == '+')) search++;
                        if(search == len - 1 || (s[search + 1]  < '0' || s[search + 1] > '9')) return false;
                        state = 2;
                    }
                    else if(s[search] < '0' || s[search] > '9') return false;
                    search++;
                    break;
                }
                case 2:{
                    //类型：底数的整数部分 + 指数 + 空格串
                    //类型：底数的整数部分 + 底数的小数部分 + 指数 + 空格串
                    //类型：底数的小数部分 + 指数 + 空格串
                    if(s[search] == ' '){
                        while( search < len && s[search] == ' ') search++;
                        if(search == len) return true;
                        else return false;
                    }
                    else if(s[search] < '0' || s[search] > '9') return false;
                    search++;
                    break;
                }
               default:break;
            }
        }
        //其他类型
        return true;
    }
};