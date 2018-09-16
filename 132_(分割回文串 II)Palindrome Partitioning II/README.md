# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 132_(分割回文串 II)Palindrome Partitioning II
## 问题描述与输入输出
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

### 问题样例

	示例1：
	输入:
	"aab"
	输出:
	1
	解释：
	进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
	
	

函数输入与输出：
* 输入：
	* string s：给定的字符串s
* 输出：
	* int: 最少分割次数

## 思路			
### 动态规划
	
	int minCut(string s) {
        if(s.size() == 0)
            return 0;
        //nums[i]记录当前子串s[0]..s[i]所需要的最小分割次数
        int len = s.size();
        vector<int> nums(len + 1, 0);
        //初始化最小分割次数
        for( int i = 0; i <= len; i++ )
            nums[i] = i - 1;
        
        for( int i = 1; i <= len; i++ ){
            //当做中心往外扩张
            for( int j = 0; j < i && i + j <= len && s[i-j-1] == s[i+j-1]; j++){
                nums[i + j]=min(nums[i + j],nums[i - j - 1] + 1);
            }
            //和右边当做中心往外扩张
            for(int j = 0; i - j > 0 && i + j + 1 <= len && s[i - 1] == s[i] && s[i - j - 1] == s[i + j]; j++ ){
                nums[i + j + 1] = min(nums[i + j + 1], nums[i - j - 1] + 1);
            }
        }
        return nums[len];
    }
	
	
## 拓展与思考：
### 拓展
暂无。
### 思考
利用动态规划可以很好的解决问题。如果你使用dp[i][j]的形式的动态规划，相对比较耗时。利用对称性可以很好的降低复杂度。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
