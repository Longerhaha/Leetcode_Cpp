# LeetCode
# Stick to practice coding of algorithmic problems everyday and you would be a good algorithm engineer someday!
## 069_(x的平方根)Sqrt(x)
## 1 问题描述、输入输出与样例
### 1.1 问题描述
实现 int sqrt(int x) 函数。<br>
计算并返回 x 的平方根，其中 x 是非负整数。<br>
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。<br>
### 1.2 输入与输出
输入：
* int x:求 x 的平方根

输出：
* int: x 的平方根
### 1.3 样例
#### 1.3.1 样例1
输入: 4<br>
输出: 2<br>
#### 1.3.2 样例2
输入: 8<br>
输出: 2<br>
解释: 8 的平方根是 2.82842..., <br>
     由于返回类型是整数，小数部分将被舍去。<br>
## 2 思路描述与代码	
### 2.1 思路描述（牛顿迭代方法）
令f(t) = x - t^2<br>
相当于求 f(t) = 0 时的 t(t >= 0)<br>
利用牛顿迭代公式可以求得 t_new = (t + x/t) / 2<br>
迭代直到 abs(t_new * t_new - x) 小于指定的精度，然后返回 (int)t_new<br>
### 2.2 代码
```cpp
double pricision = 0.00001;
int mySqrt(int x) {
    double y = 1.0 * x;
    double sqrt_y = 1;
    while( abs(y - sqrt_y * sqrt_y) > pricision ){
        sqrt_y = (sqrt_y + y / sqrt_y) / 2;
    }
    return (int)sqrt_y;
}
```
## 3 思考与拓展
### 3.1 思考
#### 3.1.1 其他方法
##### 3.1.1.1 二分法
取左边界 left 为 0， 右边界 right 为 x / 2<br>
然后算 mid = (left + right) / 2<br>
如果 mid * mid < x 则扩大左边界 left 为 mid<br>
否则 扩大右边界 right 为 mid<br>
重复上述过程直到 abs(mid * mid - x) 小于指定的精度，然后返回 (int)mid<br>

##### 3.1.1.2 平方数判定法
1 = 1<br>
1 + 3 = 2^2<br>
1 + 3 + 5 = 3^2 <br>
1 + 3 + 5 + 7 = 4^2<br>
... ...<br>
1 + 3 + 5 + 7 + ... + 2*n-1 = n^2<br>
可以看出如果求其平方根就是不断减去递增的奇数直到为0，此时减去奇数的次数就是他的平方根。
#### 3.1.2 复杂度分析
方法|空间复杂度|时间复杂度
--- | --- | ---
二分法|O(1)|O(logx)
平方数判定法|O(1)|O(x^(1/2))
牛顿迭代方法|O(1)|一般比上述两种方法好，收敛速度快
#### 3.1.3 难点分析
1. 推理牛顿迭代的公式。
### 3.2 拓展
如果让你求 x 的立方根呢？
	  
## 我一定要在这一年每天至少刷一道题，坚持不懈，持之以恒，我一定行！
