
//等级：（一遍ac）代表直接通过，（简单）代表此题简单但是没有一遍ac，（要仔细）代表此题会做(但不是特别简单)但没有一遍ac
//（可简化）代表做出来了但有更好的代码，（有思路）代表有正确思路但是没有自己做出来，没有（）是没有自己做出，（有待理解）是此题较难


//完成复习：1，2,7,10，15，20，21，22，26，33（一遍ac），
//34，36,46，48，49，50,53（一遍ac）,54，55，66，
//70（一遍ac），78,79,82，83，91,94，101（一遍ac），102（简单），103（一遍ac），
//105,121,127，136（一遍ac），138，141,150，155（一遍ac），160（简单）,169，
//179，191，198（简单），200，202（可以顺便看看92），206，207（有待理解），215，
//230（有进阶题），236,237，238（简单），239，240,287,295，297（自己做出），371，
//387

//今年新题：5（难），11，13，14,17，19，28，38,56，62（一遍ac）,
//69,73,75,88，98，108(简单），116,118,122,125，
//130（和200很像），131（有待理解），134，139，146（有待理解），148，152,162，171（一遍ac）,172
//166（有待理解），189，190，202，204,208（有待理解），217（简单）,210(和207相似），224（有待理解），227
//234，876（简单），24（简单），445，25（有空看更简洁的），242（简单），268，279，283，289
//324(没明白），328,334，341，344（一遍ac），350（简单），378，380，384，395（还未看完）
//412，454



//复习2
//19，2，141（一遍ac），142，138


//剑指offer复习
//4(有思路），5(有思路），6（要仔细），7（自己做出），9(一遍ac），11（可简化），10_01（一遍ac，简单）,10_02（一遍ac，简单）,10_03(简单），10_04（一遍ac，简单）
//15（一遍ac），16(有思路），21（其他方法），26（可简化），27，29（自己做出），31（自己做出）,34（要仔细），36（没思路），38（自己做出），
//39（注意特殊情况），40（自己做出，有其他方法），42（一遍ac，简单），43（没自己做出），45（一遍ac），49（没自己做出），50_01(一遍ac，简单）,51(没思路），53（有思路），55_01(一遍ac）
//55_02(有更好的），56_01(有思路），57_02（没思路），58_02(一遍ac），61（自己做出），62（没思路），64（没思路），65（有思路没做出），67（自己做出，要仔细），3_01(有思路，没做出）
//19（有思路）


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
//113  34
//121  63
//138  35

//142  23
//155  30
//160  52
//169  39
//179  45
//189  58_2(相似）
//191  15
//206  24
//206  6(也可以用stack做)
//215  40(相似）
//230  54

//232   9(一遍ac）
//236  68
//237  18_01(18_01更复杂）
//238  66
//239  59_01
//240  4
//260  56_01
//268（非排序）  53_02（排序）
//287  3_02
//295  41

//297  37
//371  65
//387  50_01
//

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
//提出负号：166，297
//set用的是insert
//vector<int>初始化大小：207
//组合成某样东西用dp：279,322
//状态机：289
//反转链表也能用stack做：剑指offer6
//决定边界条件可以用单个数情况判断：剑指offer11
//double不能用==：剑指offer16
//看到二叉搜索树想到中序遍历：剑指offer36
//begin,end移动时用了迭代就不要递归了

//！！！！vector，stack，queue首先要判断是否有值才可以调用值 while(i<nums.size()&&nums[i]==nums[j])；if (st.empty() || st.top() != '(')：445,2
//链表本身移动
//关于数的题考虑溢出，不要忘记最后加符号

//回溯题
//每个值不同需要for循环46，17，78
//每个值相同不需要循环22