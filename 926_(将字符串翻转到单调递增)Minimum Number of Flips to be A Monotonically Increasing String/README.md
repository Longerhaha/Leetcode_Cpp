# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 926_(将字符串翻转到单调递增)Minimum Flips of Being a Monotonically Increasing String
## 问题描述、输入输出与样例

### 问题描述

如果一个由 '0' 和 '1' 组成的字符串，是以一些 '0'（可能没有 '0'）后面跟着一些 '1'（也可能没有 '1'）的形式组成的，那么该字符串是单调递增的。

我们给出一个由字符 '0' 和 '1' 组成的字符串 S，我们可以将任何 '0' 翻转为 '1' 或者将 '1' 翻转为 '0'。

返回使 S 单调递增的最小翻转次数。

__提示__：

1. 1 <= S.length <= 20000
2. S 中只包含字符 '0' 和 '1'

### 函数输入与输出

* 输入：
	* string S：待反转的字符串
* 输出：
	* int：使 S 单调递增的最小翻转次数
	
### 问题样例

#### 示例1

输入："00110"

输出：1

解释：我们翻转最后一位得到 00111.

#### 示例2

输入："010110"

输出：2

解释：我们翻转得到 011111，或者是 000111。

#### 示例3

输入："00011000"

输出：2

解释：我们翻转得到 00000000。
	
	
## 思路描述与代码	
### 思路描述（一遍扫描法）

遍历所有的位置，按照规则(当前位置前（包括当前位置）的1变0和当前位置后（不包括当前位置）的0变1)变化后为一个递增序列，算出此时需要的最小步数 flip[i]。

min_flip = min(flip[0], flip[1], ...., flip[S_len  - 1]);

### 代码
```cpp
int minFlipsMonoIncr(string S) {
	int len_S = S.size();
	int zero_num = 0;
	for( auto s : S ) zero_num += s == '0' ? 1 : 0;
	//遍历所有的位置，算当前位置前（包括当前位置）的1变0和当前位置后（不包括当前位置）的0变1总共需要的步数，此时变化后为一个递增序列
	int zero_flip = zero_num;
	int one_flip = 0;
	int min_flip = zero_num + 0;
	for( int i = 0; i < len_S; i++ ){
		if(S[i] == '0') zero_flip--;
		else one_flip++;
		min_flip = min(min_flip, zero_flip + one_flip);
	}
	return min_flip;
}
```
## 思考与拓展
### 思考
本题还是稍微有难度，因为绕了个弯，想到反转规则后就不难了。
### 拓展
如果翻转 S 使其为单调递减呢？
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
