# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 927_(三等分)Three Equal Parts
## 问题描述、输入输出与样例

### 问题描述

给定一个由 0 和 1 组成的数组 A，将数组分成 3 个非空的部分，使得所有这些部分表示相同的二进制值。

如果可以做到，请返回任何 [i, j]，其中 i+1 < j，这样一来：

* A[0], A[1], ..., A[i] 组成第一部分；
* A[i+1], A[i+2], ..., A[j-1] 作为第二部分；
* A[j], A[j+1], ..., A[A.length - 1] 是第三部分。
* 这三个部分所表示的二进制值相等。

如果无法做到，就返回 [-1, -1]。

注意，在考虑每个部分所表示的二进制时，应当将其看作一个整体。例如，[1,1,0] 表示十进制中的 6，而不会是 3。此外，前导零也是被允许的，所以 [0,1,1] 和 [1,1] 表示相同的值。

__提示__：

1. 3 <= A.length <= 30000
2. A[i] == 0 或 A[i] == 1
 

### 函数输入与输出

* 输入：
	* vector<int>& A：由 0 和 1 组成的数组 A
* 输出：
	* vector<int>：切分的位置下标矢量
	
### 问题样例

#### 示例1

输入：[1,0,1,0,1]

输出：[0,3]
	
#### 示例2

输入：[1,1,0,1,1]

输出：[-1,-1]
	
## 思路描述与代码	
### 思路描述（计数比较法）
1. 统计数组 A 中出现的1的个数 total_1，如果不是3的倍数肯定不能被三分，如果是0则以 0, 0...0 , 0方式切割成三个部分;
2. 统计数组 A 末尾连续0的个数 cnt_third_tail_zero;

3. 遍历扫描，拆分为1的个数均匀分布的三个部分
```cpp
idx 为扫描的下标
A_len 是 vector A 的个数
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
```
4. 判断1均匀的三部分是否是合理的
```cpp
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
```

### 代码
```cpp
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
```
## 思考与拓展
### 思考
本题还是有难度的，主要要抓住三部分的1肯定是等量的来做优化。
### 拓展
如果让你分解为4部分呢？
  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
