/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode.cn/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (55.17%)
 * Likes:    3795
 * Dislikes: 0
 * Total Accepted:    1.8M
 * Total Submissions: 3.3M
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 2
 * 输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 3
 * 输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= n <= 45
 * 
 * 
 */

// @lc code=start
#include <functional>
class Solution {
public:
    int climbStairs(int n) {
        /*
            初始状态:
                d[1] = 1
                d[2] = 2

            状态转移:
                d[3] = d[3-1] + d[3-2]
                d[4] = d[4-1] + d[4-2]
                ........
                d[i] = d[i-1] + d[i-2]
                ........
                d[n] = d[n-1] + d[n-2]
        */
        if(n <= 1) return 1;
        int *d = new int[n+1];
        d[0] = 1;
        d[1] = 1;
        for(int i = 2; i <= n; ++i){
            d[i] = d[i-1] + d[i-2];
        }
        int result = d[n];
        delete[] d;
        return result;

    }
};
// @lc code=end

