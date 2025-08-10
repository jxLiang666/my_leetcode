/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode.cn/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (42.16%)
 * Likes:    1404
 * Dislikes: 0
 * Total Accepted:    616.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个 m x n 的整数数组 grid。一个机器人初始位于 左上角（即 grid[0][0]）。机器人尝试移动到 右下角（即 grid[m -
 * 1][n - 1]）。机器人每次只能向下或者向右移动一步。
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。机器人的移动路径中不能包含 任何 有障碍物的方格。
 * 
 * 返回机器人能够到达右下角的不同路径数量。
 * 
 * 测试用例保证答案小于等于 2 * 10^9。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
 * 输出：2
 * 解释：3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：obstacleGrid = [[0,1],[0,0]]
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == obstacleGrid.length
 * n == obstacleGrid[i].length
 * 1 <= m, n <= 100
 * obstacleGrid[i][j] 为 0 或 1
 * 
 * 
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        std::vector<int> dp(n, 0);

        // 处理第一行
        dp[0] = (obstacleGrid[0][0] == 0) ? 1 : 0;
        for (int j = 1; j < n; ++j) {
        // 如果当前格子没有障碍物，且左边格子有路径，则当前格子可达
            dp[j] = (obstacleGrid[0][j] == 0 && dp[j-1] > 0) ? dp[j-1] : 0;
        }

        // 从第二行开始计算
        for (int i = 1; i < m; ++i) {
            dp[0] = (obstacleGrid[i][0] == 0 && dp[0] != 0) ? 1 : 0; // 如果没有障碍物，才允许继续
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[j] = dp[j] + dp[j - 1];  // 从左和上合并
                } else {
                    dp[j] = 0;  // 遇到障碍物，路径数为0
                }
            }
        }

        return dp[n - 1];  // 返回最后一格的路径数


    }
};
// @lc code=end

