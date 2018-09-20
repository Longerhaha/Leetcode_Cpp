# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 886_(可能的二分法)Possible Binary Partition
## 问题描述、输入输出与样例

### 问题描述

给定一组 N 人（编号为 1, 2, ..., N）， 我们想把每个人分进任意大小的两组。

每个人都可能不喜欢其他人，那么他们不应该属于同一组。

形式上，如果 dislikes[i] = [a, b]，表示不允许将编号为 a 和 b 的人归入同一组。

当可以用这种方法将每个人分进两组时，返回 true；否则返回 false。

### 函数输入与输出

* 输入：
	* int N：组数的人数
	* vector<vector<int>>& dislikes：不可以分组的矢量
* 输出：
	* bool：可不可以分成两组
	
### 问题样例

	示例1:
	输入: 
	N = 4, dislikes = [[1,2],[1,3],[2,4]]

	输出: 
	True
	
	解释：
	group1 [1,4], group2 [2,3]
	
	示例2:
	输入: 
	N = 3, dislikes = [[1,2],[1,3],[2,3]]

	输出: 
	false

	示例3:
	输入: 
	N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]

	输出: 
	false
	
	
## 思路描述与代码	
### 思路描述（DFS着色法）

因为要分成两组，所以不能放在一起的成员肯定要着不同的颜色。染色方案选择为-1,1,0, 0代表未染色。

对所有的节点i：
* 如果被着色过，则跳过，因为DFS遍历过
* 否则着1色并DFS，如果存在包含i节点可划分的方案，则跳过，否则返回 false
	
判断是否存在包含i节点可划分的方案：
* 对所有不可放在一起的节点u：
	* 如果未染色则染相反的颜色,如果该方案不行则返回false
	* 如果染色了但是不符合规则照样返回false
否则的话就存在包含i节点可划分的方案，返回true。

### 代码

	class Solution {
	public:
		//染色方法
		//染色选择为-1,1,0
		//0代表未染色
		//若可以找到一种染色方案使得可以染色，那么返回true，否则返回false
		bool dfs_i_scheme(vector<vector<int>>& not_allowed_group, vector<int>& color, int i){
			//遍历不可以放在一起的点
			int len = not_allowed_group[i].size();
			for( int j = 0; j < len; j++ ){
				//如果未染色则染相反的颜色,如果该方案不行则返回false
				if(!color[not_allowed_group[i][j]]){
					color[not_allowed_group[i][j]] = -color[i];
					if(!dfs_i_scheme(not_allowed_group, color, not_allowed_group[i][j])) return false;
				} 
				//如果染色了但是不符合规则照样返回false
				else if(color[not_allowed_group[i][j]] != -color[i]) return false;
			} 
			return true;
		}
		
		bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
			vector<vector<int>> not_allowed_group(N);
			int dislikes_len = dislikes.size();
			for( int i = 0; i < dislikes_len; i++ ) not_allowed_group[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1), not_allowed_group[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
			vector<int> color(N, 0);
			for( int i = 0; i < N; i++ ){
				//如果DFS遍历过，则存在可二分的方案
				if(color[i])
					continue;
				color[i] = 1;
				//否则遍历 i 节点
				if(!dfs_i_scheme(not_allowed_group, color, i))
					return false;
			}
			return true;
		}
	};
 
## 拓展与思考：
### 拓展
本题可以用BFS做吗？
### 思考
本题重在用染色的方法解决该问题。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
