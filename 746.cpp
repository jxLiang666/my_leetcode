/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 *
 * https://leetcode.cn/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (67.88%)
 * Likes:    1647
 * Dislikes: 0
 * Total Accepted:    553.8K
 * Total Submissions: 815.8K
 * Testcase Example:  '[10,15,20]'
 *
 * 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。
 * 
 * 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
 * 
 * 请你计算并返回达到楼梯顶部的最低花费。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：cost = [10,15,20]
 * 输出：15
 * 解释：你将从下标为 1 的台阶开始。
 * - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
 * 总花费为 15 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：cost = [1,100,1,1,1,100,1,1,100,1]
 * 输出：6
 * 解释：你将从下标为 0 的台阶开始。
 * - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
 * - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
 * - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
 * 总花费为 6 。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 * 
 * 
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        /*
            初始状态:d的下标就是cost的下标 d存储的是到达该idx的最小cost
                d[0] = cost[0]
                d[1] = cost[1]
            状态转移:
                d[2] = min{d[2-2], d[2-1]} + cost[2]
                d[3] = min{d[3-2], d[3-1]} + cost[3]
                ...
                d[i] = min{d[i-2], d[i-1]} + cost[i]
                ...
                d[top] = min{d[top-1],d[top-2]} + 0
        */
        int size = cost.size();
        if(size == 1){
            return cost[0];
        }
        else if(size == 2){
            return std::min(cost[0],cost[1]);
        }
        std::vector<int> dp(size,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int idx= 2;idx<size;++idx){
            dp[idx] = std::min(dp[idx-1], dp[idx-2]) + cost[idx];
        }
        return std::min(dp[size-1],dp[size-2]);

    }
};
// @lc code=end

