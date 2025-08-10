/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode.cn/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (63.94%)
 * Likes:    1301
 * Dislikes: 0
 * Total Accepted:    443.3K
 * Total Submissions: 692.9K
 * Testcase Example:  '[1,2,2]'
 *
 * 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。
 * 
 * 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,2]
 * 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [0]
 * 输出：[[],[0]]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10
 * -10 <= nums[i] <= 10
 * 
 * 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> cur;
        std::sort(nums.begin(),nums.end());
        std::function<void(int)> backtracking = [&](int startidx) -> void {
                result.push_back(cur);
                for(int i = startidx;i<nums.size();i++){
                    if(i>startidx && nums[i] == nums[i-1]){
                        continue;
                    }
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

