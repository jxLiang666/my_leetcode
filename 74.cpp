/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode.cn/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (50.97%)
 * Likes:    1045
 * Dislikes: 0
 * Total Accepted:    551.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * 给你一个满足下述两条属性的 m x n 整数矩阵：
 * 
 * 
 * 每行中的整数从左到右按非严格递增顺序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * 输出：true
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * 输出：false
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */

// @lc code=start
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix.back().size();
        //范围相当于是 0 - m*n -1
        //假设m=3 n=4 范围为0-11
        //6在哪里 
        // 0 1 2 3
        // 4 5 6 7
        //第一行第三列 怎么求
        // 行数 : 6 / 4 = 1 ...... 2
        // 列数 : 6 % 4 = 2
        int right = m*n -1;
        int left = 0;
        
        while(right>=left){
            int mid = (left+right)/2;
            int num = matrix[mid/n][mid%n];
            if(target == num){
                return true;
            }
            else if(target > num){
                left = mid +1;
                
            }
            else{
                right = mid -1;
                // mid = (left+right)/2;
            }
        }
        return false;
    }
};
// @lc code=end

