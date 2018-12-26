class Solution {
public:
    //函数中涉及到的c++知识
    //vector<int> data; 是个长度可变的 int 数组，c++里面称为容器
    //data.empty() 判断 data 是否为空 
    //vector<int> data(26, -1); 初始化一个长度为26的长度可变 int 数组，且所有元素初始化为 -1
    
    //一遍扫描+切割法
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int len = S.size();
        //记录每个划分字母区间的右边界所处的下标
        vector<int> border;
        //记录字母第一次出现的位置
        vector<int> dict(26, -1);
        for( int i = 0; i < len; i++ ){
            //如果该字母在之前出现过
            if(dict[S[i] - 'a'] != -1){
                //合并该字母第一次出现位置到当前位置的所有区间
                while(!border.empty() && dict[S[i] - 'a'] <= border.back()) border.pop_back();
            }
            //如果未出现记录位置
            else dict[S[i] - 'a'] = i;
            //当前位置作为最后一个字母区间的右边界
            border.push_back(i);
        }
        //找出最多分段的区间右边界后，对其进行划分即可
        int len_border = border.size();
        ans.push_back(border[0] + 1);
        for( int i = 1; i < len_border; i++ ){
            ans.push_back(border[i] - border[i - 1]);
        }
        return ans;
    }
};