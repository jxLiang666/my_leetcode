/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode.cn/problems/unique-paths/description/
 *
 * algorithms
 * Medium (69.33%)
 * Likes:    2217
 * Dislikes: 0
 * Total Accepted:    972.5K
 * Total Submissions: 1.4M
 * Testcase Example:  '3\n7'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：m = 3, n = 7
 * 输出：28
 * 
 * 示例 2：
 * 
 * 
 * 输入：m = 3, n = 2
 * 输出：3
 * 解释：
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向下
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：m = 7, n = 3
 * 输出：28
 * 
 * 
 * 示例 4：
 * 
 * 
 * 输入：m = 3, n = 3
 * 输出：6
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10^9
 * 
 * 
 */

// @lc code=start
#include <vector>
#include<functional>
class Solution {
public:
    int uniquePaths(int m, int n) {
        /*
             n行 m列
            d[0][0] 是最终要求的答案 我们可以转化为d[n][m]反过来
            相当于d[0][0]是终点把其当作出发点
            从(n-1,m-1)出发 最终答案是d[n-1][m-1]

            初始状态:
                d[0][0] = 0
                d[0][1] = 1
                d[1][0] = 1
            状态转移:
                d[1][1] = d[1-1][1] + d[1][1-1]
                ...
                d[i][j] = d[i-1][j] + d[i][j-1]
                ...
                d[m-1][n-1] = d[m-1-1][n-1] + d[m-1][n-1-1]
        */
        std::vector<std::vector<int>> vec(m,std::vector<int>(n,0));
        // 非递归做法
        // // 初始化边界
        // for (int i = 0; i < m; ++i) vec[i][0] = 1;
        // for (int j = 0; j < n; ++j) vec[0][j] = 1;

        // for(int i = 1;i<m;++i){
        //     for(int j =1;j<n;++j){
        //         vec[i][j] = vec[i-1][j] + vec[i][j-1];
        //     }
        // }

        //递归做法
        std::function<int(int,int)> recursion = [&](int i, int j)  -> int {
            if(i==0 || j ==0){
                vec[i][j] = 1;
                return vec[i][j];
            }
            if(vec[i][j] != 0){
                return vec[i][j];
            }
            else{
                vec[i][j] = recursion(i-1,j) + recursion(i,j-1);
                return vec[i][j];
            }

        };
        recursion(m-1,n-1);
        return vec[m-1][n-1];

    }
};
// @lc code=end

