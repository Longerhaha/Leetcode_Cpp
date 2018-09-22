class FreqStack {
private:
    //记录当前 push 的数目，保证数据是唯一的
    int num;
    // set 记录 { x 的个数，对于栈顶元素在 push 数的计数值，以及对于的数的值 } 
    set<pair<int, pair<int, int>>> st;
    // mp 记录 x 以及 所有当前 x 出现的序号列表
    unordered_map<int, vector<int>> mp;
    
public:
    FreqStack() {
        num = 0;
    }
    
    void push(int x) {
        //如果之前出现过，则需要从 st 中删除，并更新为最新的值
        if(mp.count(x) >= 1){
            st.erase({mp[x].size(), {mp[x].back(), x}});  
        }
        //记录 x 出现的最新位置，并加入 st 中
        mp[x].push_back(num++);
        st.insert({mp[x].size(), {mp[x].back(), x}});
    }
    
    int pop() {
        auto max = *(st.rbegin());
        int ret = max.second.second;
        //更新 st 和 mp
        st.erase(max);
        if(mp[ret].size() <= 1) mp.erase(ret);
        else{
            mp[ret].pop_back();
            st.insert({mp[ret].size(), {mp[ret].back(), ret}});
        }
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */