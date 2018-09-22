# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 895_(最大频率堆栈)Stack of Maximum Frequence
## 问题描述、输入输出与样例

### 问题描述

实现 FreqStack，模拟类似栈的数据结构的操作的一个类。

FreqStack 有两个函数：

	* push(int x)，将整数 x 推入栈中。
	* pop()，它移除并返回栈中出现最频繁的元素。
		* 如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。

### 函数输入与输出

* 输入：
	* 无，以类形式要求写函数
* 输出：
	* 无，以类形式要求写函数
	
### 问题样例

	示例1:
	输入: 
	["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
	[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
	  
	输出: 
	[null,null,null,null,null,null,null,5,7,5,4]
	
	解释：
	执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

	pop() -> 返回 5，因为 5 是出现频率最高的。
	栈变成 [5,7,5,7,4]。

	pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
	栈变成 [5,7,5,4]。

	pop() -> 返回 5 。
	栈变成 [5,7,4]。

	pop() -> 返回 4 。
	栈变成 [5,7]。
	
	提示：

	* 对 FreqStack.push(int x) 的调用中 0 <= x <= 10^9。
	* 如果栈的元素数目为零，则保证不会调用  FreqStack.pop()。
	* 单个测试样例中，对 FreqStack.push 的总调用次数不会超过 10000。
	* 单个测试样例中，对 FreqStack.pop 的总调用次数不会超过 10000。
	* 所有测试样例中，对 FreqStack.push 和 FreqStack.pop 的总调用次数不会超过 150000。
	
## 思路描述与代码	
### 思路描述（基于集合与哈希表的方法）

使用 num 记录当前 push 操作的数目，保证数据是唯一的

st 记录 { x 的个数，对于栈顶元素在 push 数的计数值，以及对于的数的值 } 

mp 记录 x 以及 所有当前 x 出现的序号列表

1. push(x)操作：

如果 x 之前出现过，则需要从 st 中删除，并更新为最新的值

在 mp 中记录 x 出现的最新位置，并加入 st 中

2. pop()操作：
找到 st 中最大出现的数目，由于有记录对于的位置和数值，所以可以弹出对应的数在 mp 中的序列列表，并更新其出现次数到 st。


### 代码

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
 
## 拓展与思考：
### 拓展
如果让你写个最大频率队列呢？
### 思考
本题难度相对较高，需要去存储很多相关信息，考察思维的缜密性。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
