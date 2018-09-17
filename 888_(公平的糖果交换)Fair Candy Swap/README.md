# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 888_(公平的糖果交换)Fair Candy Swap
## 问题描述、输入输出与样例

### 问题描述
爱丽丝和鲍勃有不同大小的糖果棒：A[i] 是爱丽丝拥有的第 i 块糖的大小，B[j] 是鲍勃拥有的第 j 块糖的大小。

因为他们是朋友，所以他们想交换一个糖果棒，这样交换后，他们都有相同的糖果总量。（一个人拥有的糖果总量是他们拥有的糖果棒大小的总和。）

返回一个整数数组 ans，其中 ans[0] 是爱丽丝必须交换的糖果棒的大小，ans[1] 是 Bob 必须交换的糖果棒的大小。

如果有多个答案，你可以返回其中任何一个。保证答案存在。


### 函数输入与输出

* 输入：
	* vector<int>& A：爱丽丝拥有的糖果的一维数据的引用
	* vector<int>& B：鲍勃拥有的糖果的一维数据的引用
* 输出：
	* vector<int>：返回的第1个元素是爱丽丝必须交换的糖果棒的大小，第2个元素 是 Bob 必须交换的糖果棒的大小
	
### 问题样例

	示例1:
	输入: 
	A = [1,1], B = [2,2]
	  
	输出: 
	[1,2]

	示例2:
	输入: 
	A = [1,2], B = [2,3]
	  
	输出: 
	[1,2]
	
	示例3:
	输入: 
	A = [2], B = [1,3]
	  
	输出: 
	[2,3]
	
	示例4:
	输入: 
	A = [1,2,5], B = [2,4]
	  
	输出: 
	[5,4]
	
	提示：
	* 1 <= A.length <= 10000
	* 1 <= B.length <= 10000
	* 1 <= A[i] <= 100000
	* 1 <= B[i] <= 100000
	* 保证爱丽丝与鲍勃的糖果总量不同。
	* 答案肯定存在。
	
## 思路描述与代码	
### 思路描述（集合查找法）
1. 算 A 数组的和、B数组的和并将B数组的数据存入集合set

2. 算 A 数组的和与B数组的和的差值

3. 遍历A，查找加上A[i] + diff / 2是否在B的集合里，如果在则记录并返回

### 代码
	
	vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        //1. 算 A 数组的和、B数组的和并将B数组的数据存入集合set
        int sumA = 0;
        for( auto a : A ) sumA += a;
        unordered_set<int> set;
        int sumB = 0;
        for( auto b : B ) sumB += b, set.insert(b);
        //2. 算 A 数组的和与B数组的和的差值
        
        int diff = sumB - sumA;
        //3. 遍历A，查找加上A[i] + diff / 2是否在B的集合里，如果在则记录并返回
        for( int i = 0; i < A.size(); i++ ){
            if(set.count(A[i] + diff / 2) > 0){
                ans.push_back(A[i]);
                ans.push_back(A[i] + diff / 2);
                return ans;
            }
        }
        return ans;
    }
 
## 拓展与思考：
### 拓展
暂无想法。
### 思考
本题较为简单。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
