# leetcode
# stick to it everyday and you will be a good algorithm engineer!
## 133_Clone Graph(克隆图)
## 问题描述与输入输出
克隆一张无向图，图中的每个节点包含一个 label （标签）和一个 neighbors （邻接点）列表 。

OJ的无向图序列化：

节点被唯一标记。

我们用 # 作为每个节点的分隔符，用 , 作为节点标签和邻接点的分隔符。



### 问题样例

	示例1：
	例如，序列化无向图 {0,1,2#1,2#2,2}。

	该图总共有三个节点, 被两个分隔符  # 分为三部分。 

		1. 第一个节点的标签为 0，存在从节点 0 到节点 1 和节点 2 的两条边。
		2. 第二个节点的标签为 1，存在从节点 1 到节点 2 的一条边。
		3. 第三个节点的标签为 2，存在从节点 2 到节点 2 (本身) 的一条边，从而形成自环。
		
	我们将图形可视化如下：
	   1
      / \
     /   \
    0 --- 2
		 / \
		 \_/

函数输入与输出：
* 输入：
	* UndirectedGraphNode *node：带克隆的无向图的根节点指针
* 输出：
	* UndirectedGraphNode *: 克隆后的无向图的根节点指针

## 思路			
### DFS
	
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr)
            return nullptr;
        //利用堆栈模拟递归，节省效率，否则每次递归都需要建立哈希表，代价超级昂贵
        stack<UndirectedGraphNode *> s;
        //无序哈希表用来查重
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> ump;
        
        UndirectedGraphNode *p_copy_node = new UndirectedGraphNode(node->label);
        s.push(node);
        ump[node] = p_copy_node;
        while( !s.empty() ){
            UndirectedGraphNode *tmp = s.top();
            s.pop();
            UndirectedGraphNode *ump_tmp = ump[tmp];
            for( int i = 0; i < (tmp->neighbors).size(); i++ ){
                //如果存在映射则不需要重复建立点，直接添加即可
                UndirectedGraphNode * neghbors_tmp = (tmp->neighbors)[i];
                if(ump.count(neghbors_tmp) > 0){
                    (ump_tmp->neighbors).push_back(ump[neghbors_tmp]);
                }
                //否则需要添加、进堆栈和建立映射关系
                else{
                    UndirectedGraphNode *new_node = new UndirectedGraphNode(neghbors_tmp->label);
                    (ump_tmp->neighbors).push_back(new_node);
                    ump[neghbors_tmp] = new_node;
                    s.push(neghbors_tmp);
                }
            }
        }
        return p_copy_node; 
    }
	
	
## 拓展与思考：
### 拓展
本题其实就是[深度复制](https://blog.csdn.net/preterhuman_peak/article/details/7714664)，如果换成是链表那应该又怎么做？快去挑战[复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/)
### 思考
本题代码利用堆栈模拟递归，节省效率，否则每次递归都需要建立哈希表，代价超级昂贵。此外你可以使用BFS来解决该问题。
	  
# 希望我能在这一年坚持下来，每天都不放弃，每天都至少刷一道题，我相信我可以的！
