/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode.cn/problems/integer-break/description/
 *
 * algorithms
 * Medium (64.53%)
 * Likes:    1472
 * Dislikes: 0
 * Total Accepted:    398.6K
 * Total Submissions: 617.5K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 
 * 返回 你可以获得的最大乘积 。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: n = 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 
 * 输入: n = 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 2 <= n <= 58
 * 
 * 
 */

// @lc code=start
#include <limits.h>
class Solution {
public:
    int integerBreak(int n) {
        int result = INT_MIN;
        /*
            变量:
                d[n] 共有n个数

            初始状态:
                d[0] = 0;
                d[1] = 1;
            状态转移:
                d[2] => 1+1 => 1*(2-1) => d[1]*d[2-1]
                d[3] => 1+1+1 / 2+1 => 
        */
    }
};
// @lc code=end

