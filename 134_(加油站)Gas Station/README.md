# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 134_(加油站)Gas Station
## 问题描述与输入输出
在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。

说明: 

* 如果题目有解，该答案即为唯一答案。
* 输入数组均为非空数组，且长度相同。
* 输入数组中的元素均为非负数。

### 问题样例

	示例1：
	输入:
	gas  = [1,2,3,4,5]
	cost = [3,4,5,1,2]
	输出:
	3
	解释：
	从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
	开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
	开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
	开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
	开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
	开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
	因此，3 可为起始索引。
	
	
	示例2：
	输入:
	gas  = [2,3,4]
	cost = [3,4,3]
	输出:
	-1
	解释：
	你不能从 0 号或 1 号加油站出发，因为没有足够的汽油可以让你行驶到下一个加油站。
	我们从 2 号加油站出发，可以获得 4 升汽油。 此时油箱有 = 0 + 4 = 4 升汽油
	开往 0 号加油站，此时油箱有 4 - 3 + 2 = 3 升汽油
	开往 1 号加油站，此时油箱有 3 - 3 + 3 = 3 升汽油
	你无法返回 2 号加油站，因为返程需要消耗 4 升汽油，但是你的油箱只有 3 升汽油。
	因此，无论怎样，你都不可能绕环路行驶一周。
	

函数输入与输出：
* 输入：
	* vector<int>& gas：加油站i油量的引用
	* vector<int>& cost：从加油站i到加油站i+1的花费的引用
* 输出：
	* int: 起始索引

## 思路			
### 在线处理
	
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //node_cost[i]记录节点i到下一个节点的花费
		//total_cost记录环绕一周所需要的花费
        int len = gas.size();
        int total_cost = 0;
        vector<int> node_cost(len, 0);
        for( int i = 0; i < len; i++){
            node_cost[i] = gas[i] - cost[i]; 
            total_cost += node_cost[i];
        }
        //如果有答案
        if(total_cost >= 0){
		    //在线处理，如果当前和是负的，则更新start为下一个下标并置0
            int start = 0;
            int thisSum = 0;
            for( int i = 0; i < len; i++ ){
                thisSum += node_cost[i];
                if(thisSum < 0)
                    thisSum = 0, start = i + 1;
            }
            return start;
        }
        return -1;
    }
	
	
## 拓展与思考：
### 拓展
如果有多个答案并让你都求出来呢？
### 思考
本题完全是自己的思路，利用了在线处理思想，很骄傲自己能独立解题，加油！
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
