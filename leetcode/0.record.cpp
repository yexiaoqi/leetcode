
//完成复习：1，2,7,15，20，21，22，26，33（一遍ac），34，36,46，48，49，50,53（一遍ac）,
//54，55，66，70（一遍ac），78,79,91,94，101（一遍ac），102（简单），103（一遍ac），105

//今年新题：5（难），11，13，14,17，19，28，38,56，62（一遍ac）,69，73,75,88，98

//暂时跳过：3，10，23


//重复题
//leetcode jianzhioffer
// 8   67
//10   19
//19   22(相似）
//33   11(相似）
//34   53
//46   38(相似）
//50   16
//53   42
//54   29
//79   12
//91   46
//101  28
//102  32_01
//103  32_03
//104  55_01
//105  7


//常用方法：双指针法,unorderd_map，set去重，特殊情况考虑，位运算法，dfs用marker标记
//先对数排序:56
//防止溢出使用long：69
//双指针排序：75
//堆
//dfs用marker标记:79,46
//二叉树递归：98

//vector，stack，queue首先要判断是否有值才可以调用值 while(i<nums.size()&&nums[i]==nums[j])；if (st.empty() || st.top() != '(')
//链表本身移动
//关于数的题考虑溢出，不要忘记最后加符号

//回溯题
//每个值不同需要for循环46，17，78
//每个值相同不需要循环22