/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode.cn/problems/triangle/description/
 *
 * algorithms
 * Medium (69.30%)
 * Likes:    1431
 * Dislikes: 0
 * Total Accepted:    413.2K
 * Total Submissions: 596.2K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形 triangle ，找出自顶向下的最小路径和。
 * 
 * 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1
 * 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * 输出：11
 * 解释：如下面简图所示：
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：triangle = [[-10]]
 * 输出：-10
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 
 * 
 * 
 * 
 * 
 * 进阶：
 * 
 * 
 * 你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题吗？
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int size = triangle.size();
        int *dp = new int[size];

        for(int m =size;m>0;m--){
            for(int idx = 0; idx<m;idx++){
                if(m == size){
                    dp[idx] = triangle[m-1][idx];
                }
                else{
                    dp[idx] = triangle[m-1][idx] + std::min(dp[idx],dp[idx+1]);
                }
            }
        }

        int result = dp[0];

        delete[] dp;
        // std::cout<<result<<std::endl;
        return result;
        // int size = triangle.size();
        // int maxIdx = (1+size)*size/2;
        // int *dp = new int[maxIdx];
        // // std::cout<<"maxIdx " << maxIdx<<std::endl;
        // for(int m = size; m >0;m--){
        //     for (int i =1 ; i<=m;i++){
        //         int idx = maxIdx - i;
        //         if( m == size){
        //             dp[idx] = triangle[m-1][m-i];
        //         }
        //         else{
        //             dp[idx] = triangle[m-1][m-i] + std::min(dp[idx+m],dp[idx+m+1]);
        //         }
        //     }
        //     maxIdx  = maxIdx -m;
        // }
        // // std::cout<<dp[0]<<std::endl;
        // int result = dp[0];
        // delete []dp;
        // // std::cout<<result<<std::endl;
        // return result;
    }
};
// @lc code=end

