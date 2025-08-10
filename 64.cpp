/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode.cn/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (71.81%)
 * Likes:    1816
 * Dislikes: 0
 * Total Accepted:    766.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
 * 输出：7
 * 解释：因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：grid = [[1,2,3],[4,5,6]]
 * 输出：12
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 200
 * 0 <= grid[i][j] <= 200
 * 
 * 
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int n = grid[0].size();
        std::vector<int> dp(n,0);
        //初始化
        dp[0] = grid[0][0];
        for(int i = 1 ; i < n ; i ++){
            dp[i] = dp[i-1] + grid[0][i];
        }
        int m = grid.size();
        for(int i = 1;i<m;i++){
            for(int j = 0 ; j < n;j++){
                if(j==0){
                    dp[j] +=grid[i][j];
                }
                else{
                    dp[j] = std::min(dp[j],dp[j-1])+grid[i][j];
                }
            }
        }
        return dp[n-1];
        
    }
};
// @lc code=end

