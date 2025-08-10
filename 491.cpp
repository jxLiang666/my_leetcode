/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 *
 * https://leetcode.cn/problems/non-decreasing-subsequences/description/
 *
 * algorithms
 * Medium (52.39%)
 * Likes:    854
 * Dislikes: 0
 * Total Accepted:    224.3K
 * Total Submissions: 427.4K
 * Testcase Example:  '[4,6,7,7]'
 *
 * 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
 * 
 * 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [4,6,7,7]
 * 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [4,4,3,2,1]
 * 输出：[[4,4]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 15
 * -100 <= nums[i] <= 100
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>
#include <unordered_set>
class Solution {
public:
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> cur;

        std::function<void(int)> backtracking = [&](int startidx) -> void {
            if(cur.size() >1){
                result.push_back(cur);
            }
            std::unordered_set<int> used; // 用于本层的去重
            for(int i = startidx;i<nums.size();i++){
                if(used.find(nums[i]) != used.end()) continue;
                if(!cur.empty() && nums[i] < cur.back()) continue;

                used.insert(nums[i]);
                cur.push_back(nums[i]);
                backtracking(i+1);
                cur.pop_back();


            }

        };

        backtracking(0);
        return result;
    }
};
// @lc code=end

