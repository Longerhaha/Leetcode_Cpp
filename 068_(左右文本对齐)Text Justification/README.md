# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 068_(左右文本对齐)Text Justification
## 1 问题描述、输入输出与样例
### 1.1 问题描述
给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。<br>
你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。<br>
要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。<br>
文本的最后一行应为左对齐，且单词之间不插入额外的空格。<br>
__说明__：
1. 单词是指由非空格字符组成的字符序列。
2. 每个单词的长度大于 0，小于等于 maxWidth。
3. 输入单词数组 words 至少包含一个单词。
### 1.2 输入与输出
输入：
* vector<string> &words:输入的单词列表
* int L:每行放置的字符串的长度

输出：
* vector<string>:文本对齐后的字符串列表
### 1.3 样例
#### 1.3.1 样例1
输入:
words = ["This", "is", "an", "example", "of", "text", "justification."]<br>
maxWidth = 16<br>
输出:<br>
[<br>
   "This    is    an",<br>
   "example  of text",<br>
   "justification.  "<br>
]<br>
#### 1.3.2 样例2
输入:
words = ["What","must","be","acknowledgment","shall","be"]<br>
maxWidth = 16<br>
输出:<br>
[<br>
  "What   must   be",<br>
  "acknowledgment  ",<br>
  "shall be        "<br>
]<br>
解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",<br>
     因为最后一行应为左对齐，而不是左右两端对齐。    <br>   
     第二行同样为左对齐，这是因为这行只包含一个单词。<br>
#### 1.3.3 样例3
输入:<br>
words = ["Science","is","what","we","understand","well","enough","to","explain",<br>
         "to","a","computer.","Art","is","everything","else","we","do"]<br>
maxWidth = 20<br>
输出:<br>
[<br>
  "Science  is  what we",<br>
  "understand      well",<br>
  "enough to explain to",<br>
  "a  computer.  Art is",<br>
  "everything  else  we",<br>
  "do                  "<br>
]<br>
## 2 思路描述与代码	
### 2.1 思路描述（计数法）
l 记录当前行可以容纳的单词的总长度<br>
start 记录当前行的起始下标位置<br>
k 记录当前搜索的字符串的下标位置<br>
第一步查找当前行可以容纳的单词数<br>
然后对当前行进行对齐，对齐规则如下：<br>
* 若不是最后一行则左右对齐
* 若是最后一行左对齐并补零
### 2.2 代码
```cpp
vector<string> fullJustify(vector<string> &words, int L) {
    int words_len = words.size();
    vector<string> ans;
    int k = 0;
    while( k < words_len ){
        //当前行可以容纳的单词的总长度
        int l = 0;
        //从下标为 k 的单词开始查找
        int start = k;
        //先查找当前行可以容纳的单词数
        for( int i = 0; k < words_len && l + words[k].size() < L - i + 1; i++, k++){
            l += words[k].size();
        }
        
        //对当前行进行对齐
        //若是前 x - 1 行左右对齐
        //若是最后一行左对齐并补零
        string str;
        for( int j = start; j < k; j++ ){
            str += words[j];
            if(k < words_len){
                if(k - start - 1 == 0 || j == k - 1) continue;
                else str += string(((L - l) / (k - start - 1)) + ((j - start) < ((L - l) % (k - start - 1))), ' ');
            }
            else if(j < k - 1) str += ' ';
        }
        //最后一行有未补齐的空格
        str += string(L - str.size(), ' ');
        ans.push_back(str);
    }
    return ans;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
无。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
计数法|O(1)|O(n)
#### 3.1.3 难点分析
1. 左右对齐利用模运算来对非均匀分配空格进行处理
2. 判定是不是最后一行
### 3.2 拓展
无。
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
