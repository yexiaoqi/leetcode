
//完成复习：1，2,7,15，20，21，22，26，33（一遍ac），34，
//36,46，48，49，50,53（一遍ac）,54，55，66，70（一遍ac），
//78,79,91,94，101（一遍ac），102（简单），103（一遍ac），105,121,127
//136（一遍ac），138，141,150，155（一遍ac），160（简单）,169，179，191，198（简单）
//200，202（可以顺便看看92），206，207（有待理解），215，230（有进阶题），83，82，236,237，
//238（简单），240,287

//今年新题：5（难），11，13，14,17，19，28，38,56，62（一遍ac）,
//69,73,75,88，98，108(简单），116,118,122,125，
//130（和200很像），131（有待理解），134，139，146（有待理解），148，152,162，171（一遍ac）,172
//166（有待理解），189，190，202，204,208（有待理解），217（简单）,210(和207相似），224（有待理解），227
//234，876（简单），24（简单），445，25（有空看更简洁的），242（简单），268，279，283，289
//324(没明白），328

//暂时跳过：3，10，23



//复习2
//19，2，141（一遍ac），142，138


//重复题
//leetcode jianzhioffer
// 8   67
//10   19
//19   22(相似）
//21   25
//33   11(相似）
//34   53
//46   38(相似）
//50   16
//53   42
//54   29
//79   12

//83   18_02
//91   46
//101  28
//102  32_01
//103  32_03
//104  55_01
//105  7
//121  63
//138  35
//142  23

//155  30
//160  52
//169  39
//179  45
//189  58_2(相似）
//191  15
//215  40(相似）
//230  54
//236  68
//237  18_01(18_01更复杂）

//206  24
//238  66
//240  4
//268（非排序）  53_02（排序）
//287  3_02


//常用方法：双指针法,unorderd_map，set去重，特殊情况考虑，位运算法，dfs用marker标记
//先对数排序:56
//防止溢出使用long：69
//双指针法:125
//双指针排序：75
//堆：215，priority_queue<int, vector<int>, greater<int>> minHeap
//dfs用marker标记:79,46
//二叉树递归：98
//队列是front不是top！！：127，200，207，210
//用unordered_map和unordered_map
//提出负号：166
//set用的是insert
//vector<int>初始化大小：207
//组合成某样东西用dp：279,322
//状态机：289

//！！！！vector，stack，queue首先要判断是否有值才可以调用值 while(i<nums.size()&&nums[i]==nums[j])；if (st.empty() || st.top() != '(')：445,2
//链表本身移动
//关于数的题考虑溢出，不要忘记最后加符号

//回溯题
//每个值不同需要for循环46，17，78
//每个值相同不需要循环22