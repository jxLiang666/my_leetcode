/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.54%)
 * Likes:    1749
 * Dislikes: 0
 * Total Accepted:    862.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
 * 
 * 你可以按 任何顺序 返回答案。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4, k = 2
 * 输出：
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1, k = 1
 * 输出：[[1]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 1 
 * 
 * 
 */
#include <vector>
#include <functional>
// @lc code=start
class Solution {
public:
    std::vector<std::vector<int>> combine(int max, int num) {
        std::vector<std::vector<int>> result;
        std::vector<int> cur;

        std::function<void(int)> comb = [&](int start)->void {
            // Base case: if we have selected enough elements
            if(cur.size() == num) {
                result.push_back(cur);
                return;
            }
            
            // Try each possible next element
            for(int i = start; i <= max; i++) {
                cur.push_back(i);
                comb(i + 1);
                cur.pop_back(); // Backtrack - remove the element after exploring
            }
        };
        
        comb(1);
        return result;
    }
};
// @lc code=end

