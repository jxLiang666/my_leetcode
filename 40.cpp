/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode.cn/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (59.94%)
 * Likes:    1665
 * Dislikes: 0
 * Total Accepted:    617.7K
 * Total Submissions: 1M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 
 * 注意：解集不能包含重复的组合。 
 * 
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 * 
 * 示例 2:
 * 
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(),candidates.end());
        std::vector<std::vector<int>> result;
        std::vector<int> cur;
        int sum =0;
        std::function<void(int)> comb = [&](int start){
            if( sum == target){
                result.push_back(cur);
                return;
            }
            else if (sum > target){
                return;
            }

            for (int i = start;i<candidates.size();i++){
                if (i > start && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                cur.push_back(candidates[i]);
                sum+=candidates[i];
                comb(i+1);
                sum-=candidates[i];
                cur.pop_back();
            }
        };

        comb(0);
        return result;
    }
};
// @lc code=end

