# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 103_(二叉树的锯齿形层次遍历)Binary Tree Zigzag Level Order Traversal
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。<br>
### 1.2 输入与输出
输入：<br>
* TreeNode* root：二叉树的根节点指针<br>
输出：<br>
* vector<vector<int>>：锯齿形层次遍历的结果，是一个二维矢量的形式
### 1.3 样例
#### 1.3.1 样例1
输入: 给定二叉树: [3,9,20,null,null,15,7],
    
        3
       / \
      9  20
        /  \
       15   7

输出: 

    [
      [3],
      [20,9],
      [15,7]
    ]

## 2 思路描述与代码    
### 2.1 思路描述（基于队列的二叉树层次遍历）
二叉树的层次遍历可以利用队列来做，其思路也很简单。<br>
这里为了把每层的结果记录下来，对BFS的代码结构稍微改动了下，即里面用了个 for 循环做当前层遍历。<br>
其次与102层次遍历不一样的是，这里使用 depth 记录深度，在深度 depth 为偶数的时候对当前层次遍历结果进行反转再插入 res 中。
```cpp
初始化二叉树层次遍历的二维矢量 res ;
头结点入队;
深度初始化为0;
while( 队列不空 ){
    初始化当前层的遍历结果 level;
    获取当前层的数目数 len;
    for( int i = 0; i < len; i++ ){
        取出当前层的节点tmp并保存至 level;
        左右孩子非空则入队;
    }
    如果深度为偶数则反转 level;
    将 level 保存至 res ;
}
返回 res ;
```
比如给定二叉树: [3,9,20,null,null,15,7];<br>
首先根节点3入队，然后进入 while 循环;<br>
此时队列不空，深度为1，有1个元素3，for 循环后有 res = {[3]}, 队列里面有元素[9, 20];<br>
此时队列不空，深度为2，有元素[9, 20]，反转后为[20, 9], for 循环后有 res = {[3],[20,9]}, 队列里面有元素[15, 7];<br>
此时队列不空，深度为3，有元素[15, 7]，for 循环后有 res = {[3],[20,9], [15,7]}, 队列里面没有元素;<br>
此时队列空后，返回 res = {[3],[20,9], [15,7]} 。

### 2.2 代码
```cpp
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr)
            return res;
        //基于队列做层序遍历
        queue<TreeNode*> q;
        q.push(root);
        //层序遍历的深度
        int depth = 1;
        while( !q.empty() ){
            //保存当前层遍历的结果
            vector<int> layer;
            //获取当前层的节点数目
            int layer_size = q.size();
            //遍历当前的所有层
            for( int i = 0; i < layer_size; i++ ){
                TreeNode* tmp = q.front();
                q.pop();
                //如果左右子树非空，则入队
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                layer.push_back(tmp->val);
            }
            //将当前层遍历的结果存到res里面，同时深度加1
            if((depth & 0x01) == 0) reverse(layer.begin(), layer.end());
            res.push_back(layer);
            depth += 1;
        }
        return res;
    }
```
## 3 思考与拓展
### 3.1 思考
本题，主要考察的还是数据结构。这里为了简单，直接对深度为偶数层的遍历结果直接反转。你也可以使用双端队列或者奇层用队列、偶层用堆栈。
#### 3.1.1 其他方法
#### 3.1.1.1 基于双端队列的二叉树锯齿形层次遍历
思路还是一致的，只是数据结构换了而已。<br>
在 depth 为奇数的时候从队头出队；<br>
在 depth 为偶数的时候从队尾出队；<br>
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
基于队列的二叉树层次遍历|O(2^h),h是树的高度|O(n)
基于双端队列的二叉树锯齿形层次遍历|O(2^h),h是树的高度|O(n)，由于不需要反序，所以会比基于队列的二叉树层次遍历快一点
#### 3.1.3 难点分析
1. 采用何种数据结果保存不同方式的层遍历结果
### 3.2 拓展
如果让你结合队列和堆栈做锯齿形层次遍历呢？

      
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！

