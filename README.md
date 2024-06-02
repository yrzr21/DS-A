Personal records for practice of data structure and algorithm.

This file serves as a catalog for this repository.



# 算法集训

## 常见思路

### 暴力&枚举

#### 洛谷P1003

铺地毯问题

每次得到地毯后对矩形区域进行赋值会产生大量冗余操作

不如先得到所有地毯编号，然后对查询点，遍历地毯，得到最后的地毯编号



#### LC 59

正方形内生产螺旋矩阵

一次做完一行/列



#### 洛谷P1328

生活大爆炸石头剪刀布

- 两人各自规律性出拳,赢了加1分,其余不得分

没啥好说的，打表枚举就完事



### 前缀和 & 差分

——避免大量重复计算

1. 一维: 顺着加就完事了
2. 二维：sum\[i][j] = sum\[i-1][j] + sum\[i][j-1] + a\[i][j] - sum\[i-1][j-1]
   - i，j从1开始，矩阵sum\[0][j]和sum\[i][0]初始化为0

#### 已知数组和的数组，怎么求原数组？——差分问题

1. 一维：顺着减
2. 二维：a\[i][j] = sum\[i][j] -sum\[i-1][j] - sum\[i][j-1] +sum\[i-1][j-1]

#### more？

1. n*n个数，求(x1,y1)到(x2,y2)矩形区域的和(x1<x2,y1<y2)
   - 容斥原理的进一步应用
2. 对某区间内数字加一个数，有多次这样的操作，求该数组最终的状态
   - 标记数组，mark[l] += num，mark[r+1] -= num，求mark数组的和数组后，加到原数组上
3. 上述情况的二维情形？
   - 定义：对(x1, y1), (x2, y2)为对角顶点的矩阵加数，有多次这样的操作，求最终的矩阵
   - 分析：对于和数组，对原矩阵的某顶点加数，相当于对和矩阵从某顶点开始无限向右下延申的所有顶点加数
   - 则：mark\[x1][y1] += num, mark\[x2+1][y2+1] -= num, mark\[x2+1][y1] -= num，mark\[x1][y2+1] -= num

#### 例题

##### 洛谷B3612

##### 洛谷P1387

？？？？看不懂看不懂

##### 洛谷P3397

```C++
/* 总体思路：对于每张地毯，有：
        carpet[x1][y1]+=1,carpet[x2+1][y2+1]+=1,carpet[x1][y2+1]-=1,carpet[x2+1][y1]-=1
    对地毯矩阵求和，即可得到每个格子实际覆盖的地毯数目：
        sum[i][j]=carpet[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]
    输出即可
 */
```






# 牛客

## HJ

#### 找到最后一个单词长度

- 先进行思路设计，再写代码...不然简单题都能坑死你
- 带空格的字符串输入要用`getline(cin, str)`，单纯cin会被空格中止

#### 统计字符串中某字符出现的次数

- 不区分大小写——先统一转换为小写